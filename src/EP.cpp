#include <Core/Def.h>
#include <Core/File.h>
#include <iostream>
#ifdef MACOS
#include <cairo/cairo-quartz.h>
#include <cairo/cairo.h>
#endif

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

#ifdef MACOS
    cairo_surface_t* surface = cairo_quartz_surface_create (
              CAIRO_FORMAT_RGB24
            , 640
            , 480
            );

    cairo_t* cr = cairo_create(surface);


    cairo_set_source_rgb(cr, 0xFF, 0xFF, 0xFF);
    cairo_paint(cr);

    //draw a line from 0,0 to 100,200
    cairo_set_source_rgb(cr, 0xFF, 0, 0);
    cairo_move_to(cr, 0, 0);
    cairo_line_to(cr, 100, 200);
    cairo_stroke(cr);

    cairo_surface_write_to_png(surface, "cairo.png");
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
#endif
    return EXIT_SUCCESS;
}
