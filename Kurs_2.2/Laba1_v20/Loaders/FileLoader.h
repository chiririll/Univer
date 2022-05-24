#include <fstream>

#include "Loader.h"

#ifndef FILELOADER_H
#define FILELOADER_H

class FileLoader: public Loader {
private:
    std::string file_path;

public:
    FileLoader(): file_path("products.txt") {};
    FileLoader(const std::string &file_path): file_path(file_path) {};
    virtual ~FileLoader() = default;

    void Load(std::vector<Product>&) override;
    void Save(const std::vector<Product>&) override;
};

#endif // FILELOADER_H