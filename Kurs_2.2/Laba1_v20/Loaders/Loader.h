#include <string>
#include <vector>

#include "../Products/Product.h"

#ifndef LOADER_H
#define LOADER_H

class Loader {
private:

public:
    Loader() = default;
    virtual ~Loader()  = default;

    virtual void Load(std::vector<Product>&) = 0;
    virtual void Save(const std::vector<Product>&) = 0;
};

#endif // LOADER_H
