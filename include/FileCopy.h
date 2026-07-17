#pragma once
#include "common.h"

class FileCopy
{
public:
    FileCopy() {};
    ~FileCopy() {};
    bool CreateDirectory(const fs::path &dirName);
    bool CopyFiles(const fs::path &inputFile, const fs::path &outputDirectory);
};