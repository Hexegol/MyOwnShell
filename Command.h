#pragma once
#include <string>

class Shell;

class Command {
public:
    virtual void execute(Shell& shell) = 0;
    virtual ~Command() = default;
};

class ExitCommand : public Command
{
public:
    void execute(Shell& shell) override;
};

class CdCommand : public Command
{
private:
    std::string path;
public:
    CdCommand(const std::string& path);
    void execute(Shell& shell) override;
};
