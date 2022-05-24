#include "Command.h"

#ifndef CMD_HELP_H
#define CMD_HELP_H

class Help: public Command {
private:
    std::vector<Command*> *commands;

public:
    Help(std::vector<Command*> *commands): commands(commands) {};
    
    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_HELP_H