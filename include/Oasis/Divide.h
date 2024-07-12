//
// Created by Matthew McCall on 6/26/24.
//

#ifndef DIVIDE_H
#define DIVIDE_H

/**
 * @brief Creates a division operation expression
 *
 * This function takes two expressions and creates a new expression that
 * represents their division. The division operation is not performed
 * immediately; instead, it is encapsulated in the returned expression object.
 * Note since the operands of the division are copied when they are divided,
 * this function will free expr1 and expr2 upon invocation.
 *
 * @param expr1 The first expression in the division operation. The expression will be freed
 * @param expr2 The second expression in the division operation. The expression will be freed
 * @return struct Oa_Expression* A pointer to the created division expression
 */
struct Oa_Expression* Oa_CreateDivide(struct Oa_Expression*, struct Oa_Expression*);

/**
 * @brief Creates a division operation expression, without freeing
 *
 * This function takes two expressions and creates a new division expression
 * without freeing the original expressions. It utilizes copies of the expressions
 * for the division operation. The division operation is not performed
 * immediately; instead, it's encapsulated in the returned expression object.
 *
 * @param expr1 The first expression in the division operation. The expression will not be freed
 * @param expr2 The second expression in the division operation. The expression will not be freed
 * @return struct Oa_Expression* A pointer to the created non-freeing division expression
 */
struct Oa_Expression* Oa_CreateDivideNF(struct Oa_Expression*, struct Oa_Expression*);

#endif //DIVIDE_H