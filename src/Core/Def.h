/*
* ----------------------------------------------------------------------------------------------------------------
* History / Created by Jean-Michel Frouin on 02/10/2024.
* -----------------------------------------------------------------------------------------------------------------
* 0.0.1 - 02/10/2024 : Initial version.
*/

#ifndef __DEF_H__
#define __DEF_H__


//Bash Colors
#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define VIOLET "\e[0;35m"
#define CYAN "\e[0;36m"
#define STOP "\e[0m"

//Handle version
#define MAJOR 0
#define MINOR 0
#define RELEASE 1
#define BUILD 97
#define t(u) #u
#define VERSION(M,m,R,B) t(M) "." t(m) "." t(R) "." t(B)
#define VERSION_STRING VERSION(MAJOR,MINOR,RELEASE,BUILD)

//General app infos
#define NAME "eOS"
#define FULLNAME NAME " v" VERSION_STRING
#define LOG_FILE "eOS.log"

#include "Errors.h"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <string>

#if defined(ARM) || defined (__MARM__)
#  define PLATFORM_LITTLEINDIAN
#endif

#ifndef PLATFORM_LITTLEINDIAN
#  define PLATFORM_BIGENDIAN
#endif

extern std::mutex gMutex;

template<class T, class U>
void Log(const std::string &file, const int &line, const T &tolog, const U &tolog2)
{
    gMutex.lock();
    std::ofstream File;
    File.open(LOG_FILE, std::ios::out | std::ios::app);
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int Month = now->tm_mon + 1;
    int Day = now->tm_mday;
    int Hour = now->tm_hour;
    int Min = now->tm_min;
    int Sec = now->tm_sec;
    File << now->tm_year + 1900 << (Month < 10 ? "/0" : "/") << Month << (Day < 10 ? "/0" : "/") << Day << (
        Hour < 10 ? " 0" : " ") << Hour << (Min < 10 ? ":0" : ":") << Min << (Sec < 10 ? ":0" : ":") << Sec << '\t';
    //File << "File: " << std::setw(30) << file << " Line: " << std::setw(5) << line << " "  << tolog << tolog2 << '\n';
    File << tolog << '\t' << tolog2 << '\n';
    File.close();
    gMutex.unlock();
}

namespace Core
{
    enum ELogsLevel
    {
        eError = 0,
        eInfo = 1,
        eDebug = 2,
    };

    class Configuration
    {
        public:
            Configuration();

            ~Configuration();

            EErrors LoadConfiguration();

            EErrors SaveConfiguration();

        public:
            std::string mHTTPHost;
    };
}


#endif //__DEF_H__
