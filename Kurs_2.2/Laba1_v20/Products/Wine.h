#include <cmath>

#include "Product.h"

#ifndef PROD_WINE_H
#define PROD_WINE_H

class Wine: public Product {
private:

public:
    Wine(int id, string label, int price, double quantity, tm production_date): 
        Product(id, label, price, quantity, production_date) {};
    Wine(ProductData data): Product(data) {};
    virtual ~Wine() = default;

    string GetType() const;
    map<string, string> GetAddition() const;

    double CanBuy(double quantity) const;
    double CanRestock(double quantity) const;
    bool IsExpired() const;
};

#endif // PROD_WINE_H