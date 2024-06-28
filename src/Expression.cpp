#include <iostream>
#include <Oasis/Add.hpp>

extern "C"
{
#include "Oasis/Expression.h"

Oa_Expression* Oa_SimplifyNF(Oa_Expression* cexpr)
{
    const auto* exp = reinterpret_cast<Oasis::Expression*>(cexpr);
    auto result = exp->Simplify();
    return reinterpret_cast<Oa_Expression*>(result.release());
}

Oa_Expression* Oa_Simplify(Oa_Expression* cexpr)
{
    auto* result = Oa_SimplifyNF(cexpr);
    Oa_Free(cexpr);
    return result;
}

void Oa_Free(Oa_Expression* cexpr)
{
    const auto* exp = reinterpret_cast<Oasis::Expression*>(cexpr);
    delete exp;
}

}
