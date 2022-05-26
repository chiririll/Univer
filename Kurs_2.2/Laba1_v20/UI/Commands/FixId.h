#include "Command.h"
#include "../../Products/Product.h"

#ifndef CMD_FIXID_H
#define CMD_FIXID_H

class FixId: public Command {
private:
    std::vector<Product*> *products;

public:
    FixId(std::vector<Product*> *products): products(products) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_FIXID_H