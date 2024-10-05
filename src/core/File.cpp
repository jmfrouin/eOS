//
// Created by Jean-Michel Frouin on 04/10/2024.
//

#include "File.h"
#include <iostream>

namespace Core
{
    CFile::CFile(): fHandle(0)
    {
    }

    CFile::~CFile()
    {
        Close();
    }

    Core::EErrors CFile::Open(const std::string &name, const EMode mode, bool binary)
    {
        if (fHandle) Close();
        fName = name;

        std::cout << "CFile::Open(" << fName << ", " << mode << ");" << std::endl;
        fHandle = fopen(fName.c_str(), "r");
        if (fHandle == nullptr)
        {
            return Core::eCannotOpenFile;
        }
        return Core::eNoError;
    }

    void CFile::Close()
    {
        if (fHandle == nullptr)
            return;
        fclose(fHandle);
        fHandle = nullptr;
    }

    Core::EErrors CFile::Exists(const std::string &name)
    {
        if (FILE *f = fopen(name.c_str(), "r"))
        {
            fclose(f);
            return Core::eNoError;
        }
        return Core::eCannotOpenFile;
    }

    Core::EErrors CFile::Touch(const std::string &name)
    {
        if (FILE *f = fopen(name.c_str(), "w"))
        {
            fclose(f);
            return Core::eNoError;
        }
        return Core::eCannotOpenFile;
    }

    Core::EErrors CFile::Remove(const std::string &name)
    {
        if (remove(name.c_str()) == 0)
        {
            return Core::eNoError;
        }
        return Core::eCannotOpenFile;
    }
}