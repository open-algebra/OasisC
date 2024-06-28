//
// Created by Matthew McCall on 6/25/24.
//
#include <assert.h>

#include "Oasis/Expression.h"
#include "Oasis/Add.h"
#include "Oasis/Real.h"

int main()
{
    struct Oa_Expression* real1 = Oa_CreateReal(2);
    struct Oa_Expression* real2 = Oa_CreateReal(3);

    struct Oa_Expression* add = Oa_CreateAdd(real1, real2);
    struct Oa_Expression* result = Oa_Simplify(add);

    assert(Oa_GetValueFromReal(result) == 5);

    Oa_Free(real1);
    Oa_Free(real2);
    Oa_Free(add);
    Oa_Free(result);
}