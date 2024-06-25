//
// Created by Matthew McCall on 6/25/24.
//
#include <Oasis/Add.hpp>

extern "C"
{
#include "Oasis/Add.h"

Oa_Expression* Oa_CreateAdd(Oa_Expression* left, Oa_Expression* right)
{
    auto* cppLeft = reinterpret_cast<Oasis::Expression*>(left);
    auto* cppRight = reinterpret_cast<Oasis::Expression*>(right);

    auto* add = new Oasis::Add<> { *cppLeft, *cppRight };
    return reinterpret_cast<Oa_Expression*>(add);
}

}
