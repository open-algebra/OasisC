#include <functional>
#include <iostream>
#include <Oasis/Add.hpp>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

extern "C"
{
#include "Oasis/Expression.h"

EMSCRIPTEN_KEEPALIVE Oa_Expression* Oa_SimplifyNF(Oa_Expression* cexpr)
{
    const auto* exp = reinterpret_cast<Oasis::Expression*>(cexpr);
    auto result = exp->Simplify();
    return reinterpret_cast<Oa_Expression*>(result.release());
}

EMSCRIPTEN_KEEPALIVE Oa_Expression* Oa_Simplify(Oa_Expression* cexpr)
{
    auto* result = Oa_SimplifyNF(cexpr);
    Oa_Free(cexpr);
    return result;
}

EMSCRIPTEN_KEEPALIVE void Oa_Free(Oa_Expression* cexpr)
{
    const auto* exp = reinterpret_cast<Oasis::Expression*>(cexpr);
    delete exp;
}

EMSCRIPTEN_BINDINGS(core)
{
    function("Oa_Simplify", &Oa_Simplify, emscripten::return_value_policy::reference());
}

}
