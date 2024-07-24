//
// Created by Matthew McCall on 6/26/24.
//
#include <Oasis/Multiply.hpp>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

extern "C"
{
#include "Oasis/Multiply.h"
#include "Oasis/Expression.h"

EMSCRIPTEN_KEEPALIVE Oa_Expression* Oa_CreateMultiplyNF(Oa_Expression* left, Oa_Expression* right)
{
    const auto* cppLeft = reinterpret_cast<Oasis::Expression*>(left);
    const auto* cppRight = reinterpret_cast<Oasis::Expression*>(right);

    auto* multiply = new Oasis::Multiply<> { *cppLeft, *cppRight };
    return reinterpret_cast<Oa_Expression*>(multiply);
}

EMSCRIPTEN_KEEPALIVE Oa_Expression* Oa_CreateMultiply(Oa_Expression* left, Oa_Expression* right)
{
    auto* multiply = Oa_CreateMultiplyNF(left, right);
    Oa_Free(left);
    Oa_Free(right);
    return multiply;
}

}