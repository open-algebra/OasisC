//
// Created by Matthew McCall on 6/25/24.
//

#ifndef ADD_H
#define ADD_H


/**
 * @brief Creates an addition operation expression
 *
 * This function takes two expressions and creates a new expression that
 * represents their addition. The addition operation is not performed
 * immediately; instead, it's encapsulated in the returned expression object.
 * Note since the operands of the addition are copied when they are added,
 * this function will free expr1 and expr2 upon invocation.
 *
 * @param expr1 The first expression in the addition operation. The expression will be freed
 * @param expr2 The second expression in the addition operation. The expression will be freed
 * @return struct Oa_Expression* A pointer to the created addition expression
 */
struct Oa_Expression* Oa_CreateAdd(struct Oa_Expression*, struct Oa_Expression*);


/**
 * @brief Creates a addition operation expression, without freeing
 *
 * This function takes two expressions and creates a new addition expression
 * without freeing the original expressions. It utilizes copies of the expressions
 * for the addition operation. The addition operation is not performed
 * immediately; instead, it's encapsulated in the returned expression object.
 *
 * @param expr1 The first expression in the addition operation. The expression will not be freed
 * @param expr2 The second expression in theaddition operation. The expression will not be freed
 * @return struct Oa_Expression* A pointer to the created non-freeing addition expression
 */
struct Oa_Expression* Oa_CreateAddNF(struct Oa_Expression*, struct Oa_Expression*);

#endif //ADD_H
