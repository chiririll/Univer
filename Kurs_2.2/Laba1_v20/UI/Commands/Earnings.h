#include "Command.h"

#ifndef CMD_EARNINGS_H
#define CMD_EARNINGS_H

class Earnings: public Command {
private:
    const int &earnings;

public:
    Earnings(const int &earnings): earnings(earnings) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_EARNINGS_H