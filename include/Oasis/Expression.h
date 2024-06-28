#ifndef OASISC_LIBRARY_H
#define OASISC_LIBRARY_H

struct Oa_Expression;


/**
 * Simplifies a given expression.
 *
 * This function simplifies the given Oa_Expression struct and returns the simplified expression.
 *
 * @param[in] exp: A pointer to the Oa_Expression struct that is to be simplified.
 * @return A pointer to the simplified Oa_Expression struct.
 */
struct Oa_Expression* Oa_Simplify(struct Oa_Expression*);


/**
 * Simplifies a given expression without freeing the passed argument.
 *
 * This function simplifies the given Oa_Expression struct and returns the simplified
 * expression. Unlike the function Oa_Simplify, this function does not free the passed
 * argument (which is designated by the "NF" in the function name).
 *
 * @param[in] exp: A pointer to the Oa_Expression struct that is to be simplified.
 * @return A pointer to the simplified Oa_Expression struct.
 */
struct Oa_Expression* Oa_SimplifyNF(struct Oa_Expression*);

void Oa_Free(struct Oa_Expression*);

#endif //OASISC_LIBRARY_H
