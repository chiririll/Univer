#include "Product.h"

#ifndef PROD_BEER_H
#define PROD_BEER_H

class Beer: public Product {
private:
    tm expiration_date;
    double warehouse_size;

public:
    Beer(string label, int price, double quantity, tm production_date, tm expiration_date, double warehouse_size): 
        Product(label, price, quantity, production_date), expiration_date(expiration_date), warehouse_size(warehouse_size) {};
    Beer(ProductData data, tm expiration_date, double warehouse_size): 
        Product(data), expiration_date(expiration_date), warehouse_size(warehouse_size) {};
    virtual ~Beer();

    string GetType() const;

    double CanBuy(double quantity) const;
    double CanRestock(double quantity) const;
    bool IsExpired() const;
};

#endif // PROD_BEER_H
