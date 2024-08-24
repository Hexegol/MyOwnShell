#include "Shell.h"
#include "Command.h"
#include <sstream>
#include <memory>
#include <map>
Shell::Shell()
{

}

void Shell::displayPrompt()
{
	std::cout << "myshell>";
}

void Shell::run()
{
	while (true)
	{
		displayPrompt();
		std::string input;
		std::getline(std::cin, input);

		if (input.empty())
		{
			continue;
		}
		executeCommand(input);
	}
}

void Shell::executeCommand(const std::string& input)
{
	auto command = parseCommand(input);

	if (command) {
		command->execute(*this);
	}
}

std::unique_ptr<Command> Shell::parseCommand(const std::string& input)
{
	std::istringstream iss(input);
	std::string command;
	iss >> command;

	if (command == "cd")
	{
		std::string path;
		iss >> path;
		return std::make_unique<CdCommand>(path);
	}
	else if (command == "exit")
	{
		return std::make_unique<ExitCommand>();
	}
	else if (command == "ls")
	{
		return std::make_unique<LsCommand>();
	}
	else if (command == "pwd")
	{
		return std::make_unique<PwdCommand>();
	}
	else if (command == "mkdir")
	{
		std::string directoryName;
		iss >> directoryName;
		return std::make_unique<MkdirCommand>(directoryName);
	}
	else if (command == "rmdir")
	{
		std::string directoryName;
		
		iss >> directoryName;
		
		return std::make_unique<RmdirCommand>(directoryName);
	}
	else if (command == "touch")
	{
		std::string fileName;
		iss >> fileName;
		return std::make_unique<TouchCommand>(fileName);
	}
	else if (command == "rm")
	{
		std::string fileName;
		iss >> fileName;
		return std::make_unique<RmCommand>(fileName);
	}
	else if (command == "cat")
	{
		std::string fileName;
		iss >> fileName;
		return std::make_unique<CatCommand>(fileName);
	}
	else
	{
		std::cerr << "command not recognized : " << command << std::endl;
		return nullptr;
	}
}
