#pragma once

#include <FPL/Value.h>
//#include <FPL/Registry.h>
#include <FPL/Process.h>

FPL_BEGIN

struct ProcessCommon : Process
{
	template <class T>
	Value<T> New()
	{
		return _reg->New<T>();
	}

	template <class T>
	Value<T> New(const T& val)
	{
		return _reg->New<T>(val);
	}

	ProcessCommon() { }
	ProcessCommon(Registry &r) : _reg(&r) { }

protected:
	Registry *_reg = 0;
};

FPL_END
