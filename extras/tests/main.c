//
// Created by Matthew McCall on 7/23/24.
//
#include "munit.h"

#include "Oasis/Expression.h"
#include "Oasis/FromString.h"
#include "Oasis/MathMLSerializer.h"

int main(const int argc, char* argv[])
{
    struct Oa_Expression* result = Oa_FromInFix("2 + 2");
    munit_assert_not_null(result);

    const char* expected =
"<mrow>\n"
"    <mn>2</mn>\n"
"    <mo>+</mo>\n"
"    <mn>2</mn>\n"
"</mrow>\n";

    const char* mathml_result = Oa_ExpressionToMathMLStr(result);
    munit_assert_string_equal(expected, mathml_result);

    Oa_Free(result);
}