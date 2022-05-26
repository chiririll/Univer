#include "Command.h"
#include "../../Products/Product.h"

#ifndef CMD_LIST_H
#define CMD_LIST_H

class List: public Command {
private:
    std::vector<Product*> *products;

public:
    List(std::vector<Product*> *products): products(products) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_LIST_H