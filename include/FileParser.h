#pragma once
#include "common.h"

#include <list>

class FileParser
{
public:
    FileParser(fs::path inputDirectory, fs::path outputDirectory) : inputDirectory(inputDirectory),
                                                                    outputDirectory(outputDirectory) {}
    ~FileParser() {}
    bool ValidateData();
    bool GetFileData(std::list<std::string> &outputFiles);

private:
    fs::path inputDirectory;
    fs::path outputDirectory;
};