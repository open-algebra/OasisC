//
// Created by Matthew McCall on 6/26/24.
//

#ifndef MULTIPLY_H
#define MULTIPLY_H

/**
 * @brief Creates a multiplication operation expression
 *
 * This function takes two expressions and creates a new expression that
 * represents their multiplication. The multiplication operation is not performed
 * immediately; instead, it is encapsulated in the returned expression object.
 * Note since the operands of the multiplication are copied when they are multiplied,
 * this function will free expr1 and expr2 upon invocation.
 *
 * @param expr1 The first expression in the multiplication operation. The expression will be freed
 * @param expr2 The second expression in the multiplication operation. The expression will be freed
 * @return struct Oa_Expression* A pointer to the created multiplication expression
 */
struct Oa_Expression* Oa_CreateMultiply(struct Oa_Expression*, struct Oa_Expression*);

/**
 * @brief Creates a multiplication operation expression, without freeing
 *
 * This function takes two expressions and creates a new multiplication expression
 * without freeing the original expressions. It utilizes copies of the expressions
 * for the multiplication operation. The multiplication operation is not performed
 * immediately; instead, it's encapsulated in the returned expression object.
 *
 * @param expr1 The first expression in the multiplication operation. The expression will not be freed
 * @param expr2 The second expression in the multiplication operation. The expression will not be freed
 * @return struct Oa_Expression* A pointer to the created non-freeing multiplication expression
 */
struct Oa_Expression* Oa_CreateMultiplyNF(struct Oa_Expression*, struct Oa_Expression*);

#endif //MULTIPLY_H