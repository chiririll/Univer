#include <vector>
#include <iomanip>
#include <string>
#include <stdexcept>

#include "ErrorHandler.h"
#include "Utils.h"
#include "../Products/Product.h"
#include "../Products/Beer.h"
#include "../Products/Vodka.h"
#include "../Products/Wine.h"

using std::string, std::vector;

#ifndef PRODUCT_CREATOR_H
#define PRODUCT_CREATOR_H

class ProductCreator: public ErrorHandler {
private:
    Product* CreateBeer(ProductData data, const vector<string> &fields);
    Product* CreateVodka(ProductData data, const vector<string> &fields);
    Product* CreateWine(ProductData data, const vector<string> &fields);

public:
    ProductCreator() = default;
    ProductCreator(const string &prefix): ErrorHandler(prefix) {};
    virtual ~ProductCreator() = default;

    Product* CreateProduct(const vector<string> &fields);
};

#endif // PRODUCT_CREATOR_H