#include <iostream>
#include <string>
#include <vector>

#include "../../Products/Product.h"

#ifndef UI_CMD_H
#define UI_CMD_H

class Command {
private:

protected:
    std::vector<Product> *products;
    
public:
    Command() = default;
    Command(std::vector<Product> *products): products(products) {};
    virtual ~Command() = default;

    bool IsMe(const std::string&) const;

    virtual void Execute(std::vector<std::string> args) = 0;

    virtual std::string GetWord() const = 0;
    virtual std::string GetDescription() const = 0;
    virtual std::string GetArgs() const = 0;
};

#endif // UI_CMD_H