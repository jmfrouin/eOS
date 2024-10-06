//
// Created by Jean-Michel Frouin on 06/10/2024.
//

#include "Dir.h"
#include <filesystem>
#include <algorithm>

namespace Core {

    CDir::CDir() : fFilter(eNone) {}

    void CDir::Initialize(const std::string& ext) {
        fFilterExtentions.clear();
        if (!ext.empty()) {
            fFilterExtentions.push_back(ext);
        }
    }

    bool CDir::CD(const std::string& subdir) {
        std::filesystem::path newPath = std::filesystem::path(fDir) / subdir;
        if (std::filesystem::exists(newPath) && std::filesystem::is_directory(newPath)) {
            fDir = newPath.string();
            return true;
        }
        return false;
    }

    bool CDir::CDUp() {
        std::filesystem::path parentPath = std::filesystem::path(fDir).parent_path();
        if (std::filesystem::exists(parentPath) && std::filesystem::is_directory(parentPath)) {
            fDir = parentPath.string();
            return true;
        }
        return false;
    }

    void CDir::Filter(const int filter, const std::string& extentions) {
        fFilter = filter;
        Initialize(extentions);
    }

    const std::string CDir::Name() const {
        return std::filesystem::path(fDir).filename().string();
    }

    bool CDir::ChRoot(const std::string& root) {
        if (std::filesystem::exists(root) && std::filesystem::is_directory(root)) {
            fRoot = root;
            fDir = root;
            return true;
        }
        return false;
    }

    std::string& CDir::Normalize(std::string& dir) {
        std::replace(dir.begin(), dir.end(), '\\', '/');
        return dir;
    }

    bool CDir::mkdir(const std::string& path) {
        return std::filesystem::create_directory(path);
    }

    bool CDir::rmdir(const std::string& path) {
        return std::filesystem::remove_all(path) > 0;
    }

} // Core