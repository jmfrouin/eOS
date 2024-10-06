#include <Core/Def.h>
#include <Core/File.h>
#include <iostream>
#include <cairo/cairo-quartz.h>
#include <cairo/cairo.h>


int main()
{
    const auto start{std::chrono::steady_clock::now()};

//#if defined DEBUG
    std::cout << GREEN << "[DBG] " << RED << FULLNAME << "\n" << STOP;
    std::cout << GREEN << "[DBG] DEBUG mode\n" << STOP;
//#endif

    Core::CFile File;
    File.Open("EP.txt", Core::CFile::eWrite);
    File.Write("Hello, World!");

    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};
    std::cout << GREEN << "Elapsed time: " << elapsed_seconds.count() << "s\n" << STOP;


    cairo_surface_t* surface = cairo_quartz_surface_create (
              CAIRO_FORMAT_RGB24
            , 640
            , 480
            );

    cairo_t* cr = cairo_create(surface);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_paint(cr);
    cairo_surface_write_to_png(surface, "cairo.png");
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return EXIT_SUCCESS;
}
