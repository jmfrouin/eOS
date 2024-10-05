//
// Created by Jean-Michel Frouin on 04/10/2024.
//

#include "file.h"
#include <iostream>

CFile::CFile():
fHandle(0)
{
}

CFile::~CFile()
{
    Close();
}

const bool CFile::Open(const std::string& name, EMode mode, bool binary)
{
    if (fHandle) Close();
    fName = name;

    std::cout << "CFile::Open(" << fName << ", " <<  mode << ");" << std::endl;
    fHandle = fopen(fName.c_str(), "r");
    return (fHandle != nullptr);
}

void CFile::Close()
{
    if (fHandle == 0)
        return;
    fclose(fHandle);
    fHandle = nullptr;
}

bool CFile::Exists(const std::string& name)
{
    FILE* f = fopen(name.c_str(), "r");
    if (f)
    {
        fclose(f);
        return true;
    }
    return false;
}

