#pragma once

#include <FPL/Base.h>
#include <string>

FPL_BEGIN

/// Common to all language processes. A simple and humble class with faults
/// but crucial to the overall system.
struct Process
{
	static int trace;

	mutable bool Failed = false;
	mutable std::string Error;

protected:
	bool Fail(const char *fmt, ...) const;
	bool Fail(const std::string &) const;
};

FPL_END

