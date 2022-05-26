#include <string>
#include <vector>

#include "../Products/Product.h"
#include "../Utils/ErrorHandler.h"

#ifndef LOADER_H
#define LOADER_H

class Loader: public ErrorHandler {
public:
    Loader() = default;
    Loader(const std::string &prefix): ErrorHandler(prefix) {};
    virtual ~Loader()  = default;

    virtual bool Load(std::vector<Product*>&) = 0;
    virtual bool Save(const std::vector<Product*>&) = 0;
};

#endif // LOADER_H
