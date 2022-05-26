#include <fstream>
#include <iostream>

#include "Loader.h"
#include "../Utils/ProductCreator.h"

#ifndef FILELOADER_H
#define FILELOADER_H

class FileLoader: public Loader {
private:
    std::string file_path;

public:
    FileLoader(): file_path("products.csv") {};
    FileLoader(const std::string &file_path, const std::string &prefix = ""): 
        file_path(file_path), Loader(prefix) {};
    virtual ~FileLoader() = default;

    bool Load(std::vector<Product*>&) override;
    bool Save(const std::vector<Product*>&) override;
};

#endif // FILELOADER_H