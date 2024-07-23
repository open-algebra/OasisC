//
// Created by Matthew McCall on 7/23/24.
//
#include <memory>

#include <Oasis/Expression.hpp>
#include <Oasis/FromString.hpp>

extern "C"
{
#include "Oasis/FromString.h"

Oa_Expression* Oa_FromInFix(const char* str)
{
    if (const auto result = Oasis::FromInFix(str); result.Ok()) {
        return reinterpret_cast<Oa_Expression*>(result.GetResult().Copy().release());
    }

    return nullptr;
}

}

