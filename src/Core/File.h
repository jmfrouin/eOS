//
// Created by Jean-Michel Frouin on 04/10/2024.
//
#ifndef FILE_H
#define FILE_H

#include <string>
#include "Def.h" // Assurez-vous que ce fichier contient la définition de Core::EErrors

namespace Core
{
    /**
     * \class CFile
     * \brief A class to handle file operations.
     */
    class CFile
    {
        public:
            /**
             * \enum EMode
             * \brief File open modes.
             */
            enum EMode
            {
                eRead,      /**< Open file for reading. */
                eWrite,     /**< Open file for writing. */
                eAppend,    /**< Open file for appending. */
                eReplace,   /**< Open file for replacing. */
                eOverwrite, /**< Open file for overwriting. */
                eReadAppend /**< Open file for reading and appending. */
            };

        public:
            /**
             * \brief Default constructor.
             */
            CFile();

            /**
             * \brief Destructor.
             */
            ~CFile(void);

            /**
             * \brief Opens a file.
             * \param name The name of the file to open.
             * \param mode The mode in which to open the file.
             * \param binary Whether to open the file in binary mode.
             * \return Core::EErrors indicating success or failure.
             */
            Core::EErrors Open(const std::string &name, EMode mode, bool binary = false);

            /**
             * \brief Writes a string to the file.
             * \param str The string to write.
             * \return The number of bytes written.
             */
            const size_t Write(const std::string& str) const;

            /**
             * \brief Closes the file.
             */
            void Close();

            /**
             * \brief Checks if a file exists.
             * \param name The name of the file to check.
             * \return Core::EErrors indicating success or failure.
             */
            static Core::EErrors Exists(const std::string &name);

            /**
             * \brief Creates an empty file.
             * \param name The name of the file to create.
             * \return Core::EErrors indicating success or failure.
             */
            static Core::EErrors Touch(const std::string &name);

            /**
             * \brief Removes a file.
             * \param name The name of the file to remove.
             * \return Core::EErrors indicating success or failure.
             */
            static Core::EErrors Remove(const std::string &name);

            /**
             * \brief Gets the size of the file.
             * \return The size of the file in bytes.
             */
            const int Size() const;

            /**
             * \brief Seeks to a position in the file.
             * \param offset The offset to seek to.
             * \param origin The origin from which to seek.
             * \return The result of the seek operation.
             */
            const int Seek(int offset, int origin) const;

            /**
             * \brief Gets the current position in the file.
             * \return The current position in the file.
             */
            const int Tell() const;

        private:
            FILE *fHandle; /**< File handle. */
            EMode fMode; /**< File open mode. */
            std::string fName; /**< File name. */
    };
}

#endif //FILE_H