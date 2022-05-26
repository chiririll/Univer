#include "Command.h"
#include "../../Utils/Utils.h"
#include "../../Products/Product.h"

#ifndef CMD_REMOVE_H
#define CMD_REMOVE_H

class Remove: public Command {
private:
    std::vector<Product*> *products;

public:
    Remove(std::vector<Product*> *products): products(products) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_REMOVE_H
