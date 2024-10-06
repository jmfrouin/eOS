//
// Created by Jean-Michel Frouin on 06/10/2024.
//

#ifndef DIR_H
#define DIR_H

#include <vector>
#include <string>

namespace Core {

    /**
     * \class CDir
     * \brief A class to handle directory operations.
     */
    class CDir {
    public:
        /**
         * \enum EFilters
         * \brief Directory filter options.
         */
        enum EFilters {
            eNone     = 0, /**< No filter. */
            eFile     = 1, /**< Filter files only. */
            eFolder   = 2, /**< Filter folders only. */
            eAll      = 3, /**< Filter all. */
            eByExt    = 4  /**< Filter by extension. */
        };

    public:
        /**
         * \brief Default constructor.
         */
        CDir();

    protected:
        /**
         * \brief Initializes the directory with a specific extension filter.
         * \param ext The extension to filter by.
         */
        void Initialize(const std::string& ext);

    public:
        /**
         * \brief Changes the current directory.
         * \param subdir The subdirectory to change to.
         * \return True if successful, false otherwise.
         */
        bool CD(const std::string& subdir);

        /**
         * \brief Changes to the parent directory.
         * \return True if successful, false otherwise.
         */
        bool CDUp();

        /**
         * \brief Applies a filter to the directory contents.
         * \param filter The filter to apply.
         * \param extentions The extensions to filter by (optional).
         */
        void Filter(const int filter, const std::string& extentions);

        /**
         * \brief Gets the current directory.
         * \return The current directory.
         */
        const std::string& Dir() const { return fDir; }

        /**
         * \brief Gets the name of the current directory.
         * \return The name of the current directory.
         */
        const std::string Name() const;

        /**
         * \brief Changes the root directory.
         * \param root The new root directory.
         * \return True if successful, false otherwise.
         */
        bool ChRoot(const std::string& root);

        /**
         * \brief Normalizes a directory path.
         * \param dir The directory path to normalize.
         * \return The normalized directory path.
         */
        static std::string& Normalize(std::string& dir);

        /**
         * \brief Creates a directory.
         * \param path The path of the directory to create.
         * \return True if successful, false otherwise.
         */
        static bool mkdir(const std::string& path);

        /**
         * \brief Removes a directory.
         * \param path The path of the directory to remove.
         * \return True if successful, false otherwise.
         */
        static bool rmdir(const std::string& path);

    protected:
        std::string fDir; /**< Current directory. */
        std::string fRoot; /**< Root directory. */
        int fFilter; /**< Current filter. */
        std::vector<std::string> fFilterExtentions; /**< Filter extensions. */
    };

} // Core

#endif //DIR_H