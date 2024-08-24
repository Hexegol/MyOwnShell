#include "Command.h"
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "Shell.h"
#include <fstream>

void ExitCommand::execute(Shell& shell)
{
	std::cout << "exiting";
	exit(0);
}

CdCommand::CdCommand(const std::string& path) : path(path) {
	this->path = path;
}

namespace fs = std::filesystem;

void CdCommand::execute(Shell& shell) {
    try 
    {
        fs::current_path(path);
        std::cout << "Changed directory to: " << path << std::endl;
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << "Error changing directory: " << e.what() << std::endl;
    }
}

void LsCommand::execute(Shell& shell)
{
    std::string path = ".";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
    }
}

void PwdCommand::execute(Shell& shell)
{
    std::cout << std::filesystem::current_path() << std::endl;
}

MkdirCommand::MkdirCommand(const std::string& directoryName) : directoryName(directoryName) 
{

}
void MkdirCommand::execute(Shell& shell)
{
    try
    {
        if (std::filesystem::create_directory(directoryName))
        {
            std::cout << "directory created : " << directoryName << std::endl;
        }
        else
        {
            std::cerr << "failed to create directory" << directoryName << std::endl;
        }
    }
    catch (std::filesystem::filesystem_error& e)
    {
        std::cerr << "error creating directory : " << e.what() << std::endl;
    }

}

RmdirCommand::RmdirCommand(const std::string& directoryName) : directoryName(directoryName)
{

}

void RmdirCommand::execute(Shell& shell)
{
    if (std::filesystem::is_empty(directoryName))
    {
        try
        {
            if (std::filesystem::remove(directoryName))
            {
                std::cout << "empty directory removed " << std::endl;
            }
            else
            {
                std::cerr << "failed to remove directory" << directoryName << std::endl;
            }
        }
        catch (std::filesystem::filesystem_error& e)
        {
            std::cerr << "error removing directory : " << e.what() << std::endl;
        }
    }
    else
    {
        std::cerr << "directory is not empty" << std::endl;
    }
}


TouchCommand::TouchCommand(const std::string& directoryName) : fileName(fileName)
{

}

void TouchCommand::execute(Shell& shell)
{
    
    std::ofstream file(fileName);
    if (file) {
        std::cout << "file touched : " << fileName << std::endl;
    }
    else {
        std::cerr << "error : could not create or open file : " << fileName << std::endl;
    }
   
}

RmCommand::RmCommand(const std::string& fileName) : fileName(fileName)
{

}

void RmCommand::execute(Shell& shell)
{
    try {
        if (std::filesystem::remove(fileName)) {
            std::cout << "file '" << fileName << "' has been removed successfully" << std::endl;
        }
        else {
            std::cerr << "error : file '" << fileName << "' could not be removed, it may not exists" << std::endl;
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "error while removing file '" << fileName << "': " << e.what() << std::endl;
    }
    
}

CatCommand::CatCommand(const std::string& fileName) : fileName(fileName)
{

}

void CatCommand::execute(Shell& shell)
{
    std::ifstream file(fileName);
    if (file) {
        std::cout << "file cat-ed : " << std::endl;
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cerr << "error : could not open file : " << fileName << std::endl;
    }
}
