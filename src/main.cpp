#include <core/def.h>
#include <core/file.h>
#include <iostream>


int main()
{
    std::cout << "eOS" << std::endl;
    CFile file;
    file.Open("test.txt", CFile::eRead);

    return 0;
}
