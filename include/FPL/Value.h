#pragma once

#include <FPL/Base.h>

FPL_BEGIN

template <class T>
struct Value
{
};

struct Registry
{
	Registry();

	template <class T>
	Value<T> New()
	{
		return new Value<T>();
	}

	template <class T>
	Value<T> New(T const &X)
	{
		return new Value<T>(X);
	}
};

FPL_END


