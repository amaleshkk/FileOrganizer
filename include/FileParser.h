#pragma once
#include "common.h"

#include <vector>

class FileParser
{
public:
    FileParser(fs::path inputDirectory, fs::path outputDirectory) : inputDirectory(inputDirectory),
                                                                    outputDirectory(outputDirectory) {}
    ~FileParser() {}
    bool ValidateData();
    bool GetFileData(std::vector<std::string> &outputFiles);

private:
    fs::path inputDirectory;
    fs::path outputDirectory;
};