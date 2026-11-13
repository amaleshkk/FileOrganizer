#include "../include/FileParser.h"
#include "../include/FileCopy.h"

#include <iostream>
#include <string>
#include <thread>
#include <list>
#include <vector>
#include <memory>
#include <atomic>

void CopyFilesConcurrently(std::shared_ptr<FileCopy> fileCopy, const std::list<std::string> &outputFiles,
                           const fs::path outputDirectory, size_t maxThread)
{
    std::cout << "Copying files to " << outputDirectory << std::endl;

    if (maxThread == 0)
    {
        maxThread = 4;
    }

    std::vector<std::string> files(outputFiles.begin(), outputFiles.end());

    int numThreads = std::min(maxThread, outputFiles.size());
    if (numThreads == 0)
    {
        return;
    }

    std::atomic<int> fileIndex{0};
    std::vector<std::thread> workers;
    workers.reserve(numThreads);

    for (size_t i = 0; i < numThreads; ++i)
    {
        workers.emplace_back(
        [&]()
        {
            while (true)
            {
                size_t currIndex = fileIndex.fetch_add(1);
                if (currIndex >= files.size())
                {
                    break;
                }
                try
                {
                    fileCopy->CopyFiles(files[currIndex], outputDirectory);
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Error copying file: " << e.what() << '\n';
                }
            }
        });
    }

    for(auto& task : workers)
    {
        if(task.joinable())
        {
            task.join();
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "missing arguments..\n"
                  << "Enter input folder path and output folder path.\n"
                  << "fileOrganiser.exe \"<inputFoloder>\" \"<outputFolder>\"\n";
        return -1;
    }

    size_t maxThread = std::thread::hardware_concurrency();
    fs::path inputDirectory = argv[1];
    fs::path outputDirectory = argv[2];
    std::list<std::string> outputFiles;

    std::shared_ptr<FileParser> fileparser = std::make_shared<FileParser>(inputDirectory, outputDirectory);
    fileparser->ValidateData();
    fileparser->GetFileData(outputFiles);

    std::shared_ptr<FileCopy> fileCopy = std::make_shared<FileCopy>();

    std::list<std::thread *> copyThreads;
    std::thread *copyThread = nullptr;

    CopyFilesConcurrently(fileCopy, outputFiles, outputDirectory, maxThread);

    return 0;
}