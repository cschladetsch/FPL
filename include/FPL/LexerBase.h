#pragma once

#include <FPL/ProcessCommon.h>
#include <FPL/Slice.h>

FPL_BEGIN

int IsSpaceChar(int ch);

// Common to all lexers with different token types
class LexerBase : public ProcessCommon
{
public:
	typedef std::vector<std::string> Lines;

	LexerBase(const char *);

	const std::string &GetLine(size_t n) const
	{
		if (lines.empty() || n >= lines.size())
			throw;// TODO FPL_THROW_2(OutOfBounds, n, 0);
		return lines[n];
	}

	const Lines &GetLines() const { return lines; }
	const std::string &GetInput() const { return input; }
	int GetOffset() const { return offset; }
	int GetLineNumber() const { return offset; }
	const std::string &Line() const;
	std::string GetString(Slice const &slice) const
	{
		int length = slice.Length();
		return length == 0 ? "" : std::move(input.substr(slice.Start, length));
	}

protected:
	Lines lines;
	std::string input;
	int offset, lineNumber;
	using ProcessCommon::_reg;

	void CreateLines();
	bool LexString();
	char Current() const;
	char Next();
	bool EndOfLine() const;
	char Peek() const;
	char PeekBase() const;

	virtual void LexErrorBase(const char *msg) = 0;
	virtual void AddStringToken(int lineNumber, Slice slice) = 0;

	Slice Gather(int(*filter)(int ch));
};

FPL_END

