#include "Command.h"
#include "../../Utils/Utils.h"
#include "../../Products/Product.h"

#ifndef CMD_BUY_H
#define CMD_BUY_H

class Buy: public Command {
private:
    std::vector<Product*> *products;
    int &earnings;

public:
    Buy(std::vector<Product*> *products, int &earnings): products(products), earnings(earnings) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_BUY_H
