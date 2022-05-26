#include "Command.h"
#include "../../Loaders/FileLoader.h"

#ifndef CMD_LOAD_FILE_H
#define CMD_LOAD_FILE_H

class LoadFile: public Command {
private:
    std::vector<Product*> *products;
public:
    LoadFile(std::vector<Product*> *products): products(products) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_LOAD_FILE_H