#include <core/Def.h>
#include <core/File.h>
#include <iostream>


int main()
{
    const auto start{std::chrono::steady_clock::now()};

//#if defined DEBUG
    std::cout << GREEN << "[DBG] " << RED << FULLNAME << "\n" << STOP;
    std::cout << GREEN << "[DBG] DEBUG mode\n" << STOP;
//#endif

    Core::CFile file;
    file.Open("test.txt", Core::CFile::eRead);

    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};
    std::cout << GREEN << "Elapsed time: " << elapsed_seconds.count() << "s\n" << STOP;

    return EXIT_SUCCESS;
}
