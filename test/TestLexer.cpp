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
};

void TestLexer::AddKeyWords()
{
}

bool TestLexer::NextToken()
{
	return false;
}

void TestLexer::Terminate()
{
}

TEST_CASE("Lexer Builds", "[lexer_builds]") {
	REQUIRE(1);
}