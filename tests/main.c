//
// Created by Matthew McCall on 6/25/24.
//
#include <assert.h>

#include "Oasis/Expression.h"
#include "Oasis/Add.h"
#include "Oasis/Subtract.h"
#include "Oasis/Multiply.h"
#include "Oasis/Real.h"

int main()
{
    struct Oa_Expression* real1 = Oa_CreateReal(2);
    struct Oa_Expression* real2 = Oa_CreateReal(3);

    struct Oa_Expression* add = Oa_CreateAddNF(real1, real2);
    struct Oa_Expression* addResult = Oa_Simplify(add);

    assert(Oa_GetValueFromReal(addResult) == 5);

    struct Oa_Expression* subtract = Oa_CreateSubtractNF(real1, real2);
    struct Oa_Expression* subtractResult = Oa_Simplify(subtract);

    assert(Oa_GetValueFromReal(subtractResult) == -1);

    struct Oa_Expression* multiply = Oa_CreateMultiplyNF(real1, real2);
    struct Oa_Expression* multiplyResult = Oa_Simplify(multiply);

    assert(Oa_GetValueFromReal(multiplyResult) == 6);

    Oa_Free(real1);
    Oa_Free(real2);
    Oa_Free(addResult);
    Oa_Free(subtractResult);
    Oa_Free(multiplyResult);
}