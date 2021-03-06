#include "Product.h"

#ifndef PROD_VODKA_H
#define PROD_VODKA_H

class Vodka: public Product {
private:
    double warehouse_size;

public:
    Vodka(int id, string label, int price, double quantity, tm production_date, double warehouse_size): 
        Product(id, label, price, quantity, production_date), warehouse_size(warehouse_size) {};
    Vodka(ProductData data, double warehouse_size): 
        Product(data), warehouse_size(warehouse_size) {};
    virtual ~Vodka() = default;

    string GetType() const;
    map<string, string> GetAddition() const;

    double CanBuy(double quantity) const;
    double CanRestock(double quantity) const;
    bool IsExpired() const;
};

#endif // PROD_VODKA_H