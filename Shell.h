#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Command.h"
#include "ProcessManager.h"
#include "IOManager.h"
#ifndef SHELL_H
#define SHELL_H


class Shell {
private:
    ProcessManager processManager;
    IOManager ioManager;

    void displayPrompt();
    void executeCommand(const std::string& input);
    std::unique_ptr<Command> parseCommand(const std::string& input);
public:
	Shell();
	void run();
};
#endif

