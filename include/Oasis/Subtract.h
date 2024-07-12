//
// Created by Matthew McCall on 6/25/24.
//

#ifndef SUBTRACT_H
#define SUBTRACT_H

/**
 * @brief Creates a subtraction operation expression
 *
 * This function takes two expressions and creates a new expression that
 * represents their subtraction. The subtraction operation is not performed
 * immediately; instead, it is encapsulated in the returned expression object. 
 * Note since the operands of the subtraction are copied when they are subtracted,
 * this function will free expr1 and expr2 upon invocation.
 *
 * @param expr1 The first expression in the subtraction operation. The expression will be freed
 * @param expr2 The second expression in the subtraction operation. The expression will be freed
 * @return struct Oa_Expression* A pointer to the created subtraction expression
 */
struct Oa_Expression* Oa_CreateSubtract(struct Oa_Expression*, struct Oa_Expression*);

/**
 * @brief Creates a subtraction operation expression, without freeing
 *
 * This function takes two expressions and creates a new subtraction expression
 * without freeing the original expressions. It utilizes copies of the expressions
 * for the subtraction operation. The subtraction operation is not performed
 * immediately; instead, it's encapsulated in the returned expression object.
 *
 * @param expr1 The first expression in the subtraction operation. The expression will not be freed
 * @param expr2 The second expression in the subtraction operation. The expression will not be freed
 * @return struct Oa_Expression* A pointer to the created non-freeing subtraction expression
 */
struct Oa_Expression* Oa_CreateSubtractNF(struct Oa_Expression*, struct Oa_Expression*);

#endif //SUBTRACT_H