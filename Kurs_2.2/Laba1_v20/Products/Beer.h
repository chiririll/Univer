#include <ctime>

#include "Product.h"

#ifndef PROD_WINE_H
#define PROD_WINE_H

class Beer: public Product {
private:
    time_t expiration_date;
    double warehouse_size;

public:
    Beer(string label, std::time_t expiration_date, int price, double quantity, double warehouse_size): 
        Product(label, price, quantity), expiration_date(expiration_date), warehouse_size(warehouse_size) {};
    virtual ~Beer();

    string GetType() const;

    double CanBuy(double quantity) const;
    double CanRestock(double quantity) const;
    bool IsExpired() const;
};

#endif // PROD_WINE_H