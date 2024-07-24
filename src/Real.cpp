//
// Created by Matthew McCall on 6/25/24.
//

#include <Oasis/Real.hpp>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

extern "C"
{
#include "Oasis/Real.h"

EMSCRIPTEN_KEEPALIVE Oa_Expression* Oa_CreateReal(double val)
{
    auto* real = new Oasis::Real { val };
    return reinterpret_cast<Oa_Expression*>(real);
}

EMSCRIPTEN_KEEPALIVE double Oa_GetValueFromReal(Oa_Expression* creal)
{
    const auto* real = reinterpret_cast<Oasis::Real*>(creal);
    return real->GetValue();
}

}



