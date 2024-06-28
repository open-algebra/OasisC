# OasisC

This project provides a C wrapper around the [Oasis](https://github.com/open-algebra/Oasis) library, a C++ library for computer algebra. It's designed to make the Oasis library accessible in projects written in C.

## How to Use OasisC

In order to use OasisC, you will need to include the Oasis header files in your C code as follows:

```C
#include "Oasis/Expression.h"
#include "Oasis/Add.h"
#include "Oasis/Real.h"
```

Once that's done, you'll have access to all of the functions provided by the Oasis library through the C wrapper.

Here are some examples of how you can create, add, and simplify real numbers using the OasisC library:

```C
struct Oa_Expression* real1 = Oa_CreateReal(2);
struct Oa_Expression* real2 = Oa_CreateReal(3);

struct Oa_Expression* add = Oa_CreateAdd(real1, real2);
struct Oa_Expression* result = Oa_Simplify(add);
```

Finally, you can get the value from your resultant real number:

```C
double value = Oa_GetValueFromReal(result);
```