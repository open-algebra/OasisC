//
// Created by Matthew McCall on 6/26/24.
//
#include <Oasis/Divide.hpp>

extern "C"
{
#include "Oasis/Divide.h"
#include "Oasis/Expression.h"

Oa_Expression* Oa_CreateDivideNF(Oa_Expression* left, Oa_Expression* right)
{
    const auto* cppLeft = reinterpret_cast<Oasis::Expression*>(left);
    const auto* cppRight = reinterpret_cast<Oasis::Expression*>(right);

    auto* divide = new Oasis::Divide<> { *cppLeft, *cppRight };
    return reinterpret_cast<Oa_Expression*>(divide);
}

Oa_Expression* Oa_CreateDivide(Oa_Expression* left, Oa_Expression* right)
{
    auto* divide = Oa_CreateDivideNF(left, right);
    Oa_Free(left);
    Oa_Free(right);
    return divide;
}

}