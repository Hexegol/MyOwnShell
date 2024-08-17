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
	else
	{
		std::cerr << "command not recognized : " << command << std::endl;
		return nullptr;
	}
}
