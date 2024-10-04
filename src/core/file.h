//
// Created by Jean-Michel Frouin on 04/10/2024.
//

#ifndef FILE_H
#define FILE_H

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
    
     const bool Open(const std::string& name, EMode mode, bool binary = false);

    /*!
     *@brief Close the file.
     */
    void Close();
};


#endif //FILE_H
