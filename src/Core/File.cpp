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
        fMode = mode;

        std::cout << "CFile::Open(" << fName << ", " << fMode << ");" << std::endl;
        fHandle = fopen(fName.c_str(), fMode == eRead ? "r" : "w");
        if (fHandle == nullptr)
        {
            return Core::eCannotOpenFile;
        }
        return Core::eNoError;
    }

    size_t CFile::Write(const std::string &str) const
    {
        if(fMode == eRead)
            return 0;
        if (fHandle == nullptr)
            return 0;
        return fwrite(str.c_str(), 1, str.size(), fHandle);
    }

    const size_t CFile::Read(void *ptr, const size_t size, const size_t count) const
    {
        if (fHandle == nullptr)
            return 0;
        return fread(ptr, size, count, fHandle);
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

    const int CFile::Size() const
    {
        if (fHandle == nullptr)
            return -1;
        fseek(fHandle, 0, SEEK_END);
        return ftell(fHandle);
    }

    const int CFile::Seek(int offset, int origin) const
    {
        if (fHandle == nullptr)
            return -1;
        return fseek(fHandle, offset, origin);
    }

    const int CFile::Tell() const
    {
        if (fHandle == nullptr)
            return -1;
        return ftell(fHandle);
    }
}