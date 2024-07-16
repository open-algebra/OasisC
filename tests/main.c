//
// Created by Matthew McCall on 6/25/24.
//
#include "munit.h"

#include "Oasis/Expression.h"
#include "Oasis/Add.h"
#include "Oasis/Subtract.h"
#include "Oasis/Multiply.h"
#include "Oasis/Divide.h"
#include "Oasis/Real.h"

#define DESERIALIZE_REALS(reals) \
    struct Oa_Expression** realsArr = (struct Oa_Expression**) reals; \
    struct Oa_Expression* real1 = realsArr[0]; \
    struct Oa_Expression* real2 = realsArr[1];

static void* test_setup(const MunitParameter params[], void* user_data)
{
    struct Oa_Expression* real1 = Oa_CreateReal(2);
    struct Oa_Expression* real2 = Oa_CreateReal(3);

    struct Oa_Expression** realsArr = (struct Oa_Expression**)malloc(sizeof(struct Oa_Expression*) * 2);
    realsArr[0] = real1;
    realsArr[1] = real2;

    return realsArr;
}

static void test_tear_down(void* fixture)
{
    DESERIALIZE_REALS(fixture);

    Oa_Free(real1);
    Oa_Free(real2);

    free(fixture);
}

MunitResult test_addition(const MunitParameter params[], void* fixture)
{
    DESERIALIZE_REALS(fixture);

    struct Oa_Expression* add = Oa_CreateAddNF(real1, real2);
    struct Oa_Expression* addResult = Oa_Simplify(add);

    munit_assert_float(Oa_GetValueFromReal(addResult), ==, 5);

    Oa_Free(addResult);
    return MUNIT_OK;
}

MunitResult test_subtraction(const MunitParameter params[], void* fixture)
{
    DESERIALIZE_REALS(fixture);

    struct Oa_Expression* subtract = Oa_CreateSubtractNF(real1, real2);
    struct Oa_Expression* subtractResult = Oa_Simplify(subtract);

    munit_assert_float(Oa_GetValueFromReal(subtractResult), ==, -1);

    Oa_Free(subtractResult);
    return MUNIT_OK;
}

MunitResult test_multiplication(const MunitParameter params[], void* fixture)
{
    DESERIALIZE_REALS(fixture);

    struct Oa_Expression* multiply = Oa_CreateMultiplyNF(real1, real2);
    struct Oa_Expression* multiplyResult = Oa_Simplify(multiply);

    munit_assert_float(Oa_GetValueFromReal(multiplyResult), ==, 6);

    Oa_Free(multiplyResult);
    return MUNIT_OK;
}

MunitResult test_division(const MunitParameter params[], void* fixture)
{
    DESERIALIZE_REALS(fixture);

    struct Oa_Expression* divide = Oa_CreateDivideNF(real1, real2);
    struct Oa_Expression* divideResult = Oa_Simplify(divide);

    munit_assert_double_equal(Oa_GetValueFromReal(divideResult), 0.667, 3);

    Oa_Free(divideResult);
    return MUNIT_OK;
}

int main(const int argc, char* argv[])
{
    MunitTest arithmeticTests[] = {
        {
            "Addition",
            test_addition,
            test_setup,
            test_tear_down,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "Subtraction",
            test_subtraction,
            test_setup,
            test_tear_down,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "Multiplication",
            test_multiplication,
            test_setup,
            test_tear_down,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "Division",
            test_division,
            test_setup,
            test_tear_down,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    const MunitSuite arithmeticSuite = {
        "Arithmetic/",
        arithmeticTests,
        NULL,
        1,
        MUNIT_SUITE_OPTION_NONE
    };

    return munit_suite_main(&arithmeticSuite, NULL, argc, argv);
}