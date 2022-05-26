#include <iostream>
#include <vector>

#include "Commands/Command.h"
#include "Commands/Help.h"
#include "Commands/List.h"
#include "Commands/Clear.h"
#include "Commands/LoadFile.h"
#include "Commands/SaveFile.h"
#include "../Products/Product.h"
#include "../Loaders/Loader.h"

#ifndef UI_H
#define UI_H

class UI {
private:
    std::vector<Command*> commands;
    std::vector<Product*> products;

    // Utils
    void SplitCmd(std::string, std::vector<std::string>&) const;
    void Exit(int) const;

public:
    UI();
    virtual ~UI();

    bool ReadCommand();
    void StartLoop();
};

#endif // UI_H