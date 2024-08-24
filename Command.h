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

class LsCommand : public Command
{
public:
    void execute(Shell& shell) override;
};

class PwdCommand : public Command
{
public:
    void execute(Shell& shell) override;
};

class MkdirCommand : public Command
{
private:
    std::string directoryName;
public:
    explicit MkdirCommand(const std::string& directoryName);
    void execute(Shell& shell) override;
};


class RmdirCommand : public Command
{
private:
    std::string directoryName;
public:
    explicit RmdirCommand(const std::string& directoryName);
    void execute(Shell& shell) override;
};

class TouchCommand : public Command
{
private:
    std::string fileName;
public:
    explicit TouchCommand(const std::string& fileName);
    void execute(Shell& shell) override;
};

class RmCommand : public Command
{
private:
    std::string fileName;
public:
    explicit RmCommand(const std::string& fileName);
    void execute(Shell& shell) override;
};

class CatCommand : public Command
{
private:
    std::string fileName;
public:
    explicit CatCommand(const std::string& fileName);
    void execute(Shell& shell) override;
};
