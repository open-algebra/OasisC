//
// Created by Matthew McCall on 7/23/24.
//
#include <cstring>
#include <Oasis/MathMLSerializer.hpp>

extern "C"
{
#include "Oasis/MathMLSerializer.h"

const char* Oa_ExpressionToMathMLStr(Oa_Expression* cexpr)
{
    const auto* expr = reinterpret_cast<Oasis::Expression*>(cexpr);

    tinyxml2::XMLDocument doc;
    Oasis::MathMLSerializer serializer(doc);

    expr->Serialize(serializer);
    doc.InsertEndChild(serializer.GetResult());

    tinyxml2::XMLPrinter printer;
    doc.Print(&printer);

    auto result = new char[printer.CStrSize()];
    strlcpy(result, printer.CStr(), printer.CStrSize());

    return result;
}

}
