#include <iostream>
#include <string>
#include <vector>

#ifndef UI_CMD_H
#define UI_CMD_H

class Command {
public:
    Command() = default;
    virtual ~Command() = default;

    bool IsMe(const std::string&) const;

    virtual void Execute(std::vector<std::string> args) = 0;

    virtual std::string GetWord() const = 0;
    virtual std::string GetDescription() const = 0;
    virtual std::string GetArgs() const = 0;
};

#endif // UI_CMD_H