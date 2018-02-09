#pragma once

#include "FPL/Base.h"

FPL_BEGIN

class PiTranslator;
class RhoTranslator;

enum class Language { None, Pi, Rho, Tau };
const char *ToString(Language);

FPL_END

