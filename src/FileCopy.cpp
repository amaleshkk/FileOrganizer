#include "../include/FileCopy.h"

#include <iostream>
#include <mutex>
#include <filesystem>

std::mutex dirMutex;

bool FileCopy::CreateDirectory(const fs::path &dirName)
{
    bool created = false;

    if (!fs::exists(dirName))
    {
        bool created = fs::create_directories(dirName);
    }

    return created;
}

bool FileCopy::CopyFiles(const fs::path& inputFile, const fs::path& outputDirectory)
{
    auto copyOptions = fs::copy_options::recursive | fs::copy_options::update_existing;

    std::string dir_name = inputFile.extension().string();
    
    if(!dir_name.empty() && dir_name[0] == '.')
    {
        dir_name = dir_name.substr(1);
    }

    fs::path outputFileDir = outputDirectory / fs::path(dir_name);
    
    try{
        bool copyFile = true;

        if(!fs::exists(outputFileDir))
        {
            std::lock_guard<std::mutex> lock(dirMutex);
            if(!fs::exists(outputFileDir))
            {
                bool dirCreation = CreateDirectory(outputFileDir);
                if(dirCreation)
                {
                    copyFile = false;
                }
            }
        }
        if(copyFile)
        {
            fs::copy(inputFile, outputFileDir, copyOptions);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return true;
}