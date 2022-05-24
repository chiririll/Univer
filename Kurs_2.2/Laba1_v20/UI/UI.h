#include <iostream>
#include <vector>

#include "Commands/Command.h"
#include "Commands/Help.h"
#include "../Products/Product.h"
#include "../Loaders/Loader.h"

#ifndef UI_H
#define UI_H

class UI {
private:
    std::vector<Command*> commands;
    std::vector<Product> products;
    Loader* products_loader;

    // Utils
    void SplitCmd(std::string, std::vector<std::string>&) const;

public:
    UI(Loader*);
    virtual ~UI();

    bool ReadCommand();
    void StartLoop();
};

#endif // UI_H