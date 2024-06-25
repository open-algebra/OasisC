//
// Created by Matthew McCall on 6/25/24.
//

#include <Oasis/Real.hpp>

extern "C"
{
#include "Oasis/Real.h"

Oa_Expression* Oa_CreateReal(double val)
{
    auto* real = new Oasis::Real { val };
    return reinterpret_cast<Oa_Expression*>(real);
}

double Oa_GetValueFromReal(Oa_Expression* creal)
{
    const auto* real = reinterpret_cast<Oasis::Real*>(creal);
    return real->GetValue();
}

}



