//
// Created by Matthew McCall on 6/25/24.
//

#ifndef REAL_H
#define REAL_H


/**
 * @brief This function creates a new `Oa_Expression` object representing a `Real` number.
 *
 * @param val The `double` value that the newly created `Oa_Expression` object will hold.
 *
 * @return A pointer to a `Oa_Expression` object containing the value of `val`.
 */
struct Oa_Expression* Oa_CreateReal(double val);


/**
 * @brief Gets the real value from an `Oa_Expression` object.
 *
 * @param expr A pointer to a `Oa_Expression` object.
 *
 * @return A `double` value contained in the given `Oa_Expression` object.
 */
double Oa_GetValueFromReal(struct Oa_Expression*);

#endif //REAL_H
