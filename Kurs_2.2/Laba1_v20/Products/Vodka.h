#include "Product.h"

#ifndef PROD_WINE_H
#define PROD_WINE_H

class Vodka: public Product {
private:
    double warehouse_size;

public:
    Vodka(string label, int price, double quantity, double warehouse_size): 
        Product(label, price, quantity), warehouse_size(warehouse_size) {};
    virtual ~Vodka();

    string GetType() const;

    double CanBuy(double quantity) const;
    double CanRestock(double quantity) const;
    bool IsExpired() const;
};

#endif // PROD_WINE_H