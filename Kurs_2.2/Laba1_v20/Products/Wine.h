#include <cmath>

#include "Product.h"

#ifndef PROD_WINE_H
#define PROD_WINE_H

class Wine: public Product {
private:

public:
    Wine(string label, int price, double quantity, time_t production_date): 
        Product(label, price, quantity, production_date) {};
    Wine(ProductData data): Product(data) {};
    virtual ~Wine();

    string GetType() const;

    double CanBuy(double quantity) const;
    double CanRestock(double quantity) const;
    bool IsExpired() const;
};

#endif // PROD_WINE_H