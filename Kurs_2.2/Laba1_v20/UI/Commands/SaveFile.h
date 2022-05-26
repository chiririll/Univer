#include "Command.h"
#include "../../Loaders/FileLoader.h"

#ifndef CMD_SAVE_FILE_H
#define CMD_SAVE_FILE_H

class SaveFile: public Command {
private:
    std::vector<Product*> *products;
public:
    SaveFile(std::vector<Product*> *products): products(products) {};

    void Execute(std::vector<std::string> args) override;

    std::string GetWord() const override;
    std::string GetDescription() const override;
    std::string GetArgs() const override;
};

#endif // CMD_SAVE_FILE_H
