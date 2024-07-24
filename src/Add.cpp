//
// Created by Matthew McCall on 6/25/24.
//
#include <Oasis/Add.hpp>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

extern "C"
{
#include "Oasis/Add.h"
#include "Oasis/Expression.h"

EMSCRIPTEN_KEEPALIVE Oa_Expression* Oa_CreateAddNF(Oa_Expression* left, Oa_Expression* right)
{
    const auto* cppLeft = reinterpret_cast<Oasis::Expression*>(left);
    const auto* cppRight = reinterpret_cast<Oasis::Expression*>(right);

    auto* add = new Oasis::Add<> { *cppLeft, *cppRight };
    return reinterpret_cast<Oa_Expression*>(add);
}

EMSCRIPTEN_KEEPALIVE Oa_Expression* Oa_CreateAdd(Oa_Expression* left, Oa_Expression* right)
{
    auto* add = Oa_CreateAddNF(left, right);
    Oa_Free(left);
    Oa_Free(right);
    return add;
}

}
