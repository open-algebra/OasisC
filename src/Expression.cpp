#include <iostream>

extern "C"
{
#include "Oasis/Expression.h"

void hello(void)
{
    std::cout << "Hello, world!" << std::endl;
}

}
