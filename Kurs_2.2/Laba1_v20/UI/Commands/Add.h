#include "Command.h"
#include "../../Products/Product.h"
#include "../../Utils/ProductCreator.h"

#ifndef CMD_ADD_H
#define CMD_ADD_H

class Add: public Command {
private:
    std::vector<Product*> *products;

public:
    Add(std::vector<Product*> *products): products(products) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_ADD_H
