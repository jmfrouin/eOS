#include <core/def.h>
#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    for(int i=10; i--; )
    {
        std::cout << i << std::endl;
    }
    return 0;
}
