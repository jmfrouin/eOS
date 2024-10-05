//
// Created by Jean-Michel Frouin on 04/10/2024.
//
#ifndef FILE_H
#define FILE_H

#include <string>
#include "Def.h" // Assurez-vous que ce fichier contient la définition de Core::EErrors

namespace Core
{
    class CFile
    {
        public:
        enum EMode
        {
            eRead,
            eWrite,
            eAppend,
            eReplace,
            eOwerwrite,
            eReadAppend
        };

        public:
        CFile();

        /*!
         *@brief Releases any ressources held by the file.
         */
        ~CFile(void);

        Core::EErrors Open(const std::string& name, EMode mode, bool binary = false);

        /*!
         *@brief Close the file.
         */
        void Close();

        static Core::EErrors Exists(const std::string& name);
        static Core::EErrors Touch(const std::string& name);
        static Core::EErrors Remove(const std::string& name);

        private:
        FILE* fHandle;
        std::string fName;
    };
}

#endif //FILE_H