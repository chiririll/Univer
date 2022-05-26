#include "Command.h"
#include "../../Products/Product.h"

#ifndef CMD_CLEAR_H
#define CMD_CLEAR_H

class Clear: public Command {
private:
    std::vector<Product*> *products;

public:
    Clear(std::vector<Product*> *products): products(products) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_CLEAR_H
