#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "FPL/TokenBase.h"
#include "FPL/LexerCommon.h"

using namespace fpl;


struct TestTokenEnumType
{
	enum Enum
	{
		None = 0,
		Whitepsace = 1,
		Semi = 2,
		Int = 3,
		Float = 4,
		String = 5,
		True = 6,
		False = 7,
		Ient = 8,
		OpenSqaureBracket = 9,
		CloseSqaureBracket = 10,
		OpenBrace = 11,
		CloseBrace = 12,
		Struct = 13,
		Ident = 14,
	};

	struct Type : TokenBase<TestTokenEnumType>
	{
		Type() { }

		Type(Enum val, const LexerBase &lexer, int ln, Slice slice)
			: TokenBase<TestTokenEnumType>(val, lexer, ln, slice) { }
	};

	static const char *ToString(Enum val);
};

struct TestLexer : LexerCommon<TestTokenEnumType>
{
	typedef LexerCommon<TestTokenEnumType> Parent;
	typedef TokenBase<TestTokenEnumType> TokenNode;

	TestLexer(const char *text) : Parent(text) { }

	void AddKeyWords() override;
	bool NextToken() override;
	void Terminate() override;

	bool LexIdent();
};

void TestLexer::AddKeyWords()
{
	keyWords["struct"] = Enum::Struct;
	keyWords["true"] = Enum::True;
	keyWords["false"] = Enum::False;
}

bool TestLexer::NextToken()
{
	char current = Current();
	if (current == 0)
		return false;

	if (isalpha(current))
		return LexIdent();

	if (isdigit(current))
		return Add(Enum::Int, Gather(isdigit));

	switch (current)
	{
	case ';': return Add(Enum::Semi);
	case '{': return Add(Enum::OpenBrace);
	}

	LexError("Unrecognised %c");

	return false;
}

void TestLexer::Terminate()
{
}

bool TestLexer::LexIdent()
{
	auto tok = LexAlpha();
	tokens.push_back(tok);
	return true;
}

TEST_CASE("Lexer Builds", "[lexer_builds]")
{
	const char *input = "struct Foo { int n; string f; }";
	auto lex = TestLexer(input);
	REQUIRE(!lex.Failed);
}