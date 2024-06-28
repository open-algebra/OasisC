#ifndef OASISC_LIBRARY_H
#define OASISC_LIBRARY_H

struct Oa_Expression;

struct Oa_Expression* Oa_Simplify(struct Oa_Expression*);
struct Oa_Expression* Oa_SimplifyNF(struct Oa_Expression*);

void Oa_Free(struct Oa_Expression*);

#endif //OASISC_LIBRARY_H
