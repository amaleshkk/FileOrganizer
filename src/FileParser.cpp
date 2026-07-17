#include "../include/FileParser.h"

#include <iostream>
#include <filesystem>
#include <list>

bool FileParser::ValidateData()
{
    if (!std::filesystem::exists(inputDirectory))
    {
        std::cout << inputDirectory << " not found.\nExiting...";
        exit(0);
    }

    return true;
}

bool FileParser::GetFileData(std::list<std::string> &outputFiles)
{
    for (const auto &files : fs::recursive_directory_iterator(inputDirectory))
    {
        if (!fs::is_directory(files))
        {
            outputFiles.push_back(files.path().string());
        }
    }
    return true;
}