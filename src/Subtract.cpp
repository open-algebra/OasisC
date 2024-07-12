//
// Created by Matthew McCall on 6/25/24.
//
#include <Oasis/Subtract.hpp>

extern "C"
{
#include "Oasis/Subtract.h"
#include "Oasis/Expression.h"

Oa_Expression* Oa_CreateSubtractNF(Oa_Expression* left, Oa_Expression* right)
{
    const auto* cppLeft = reinterpret_cast<Oasis::Expression*>(left);
    const auto* cppRight = reinterpret_cast<Oasis::Expression*>(right);

    auto* subtract = new Oasis::Subtract<> { *cppLeft, *cppRight };
    return reinterpret_cast<Oa_Expression*>(subtract);
}

Oa_Expression* Oa_CreateSubtract(Oa_Expression* left, Oa_Expression* right)
{
    auto* subtract = Oa_CreateSubtractNF(left, right);
    Oa_Free(left);
    Oa_Free(right);
    return subtract;
}

}