#include "Command.h"
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "Shell.h"

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
