#include <string>
#include <ctime>

#ifndef PRODUCT_H
#define PRODUCT_H

using std::string;
using std::tm;

struct ProductData {
    string label;
    int price;
    double quantity;
    tm production_date;

    ProductData() = default;
    ProductData(string label, int price, double quantity, tm producrion_date): 
        label(label), price(price), quantity(quantity), production_date(production_date) {};
};

class Product {
private:
    ProductData data;

public:
    Product(string label, int price, double quantity, tm production_date): 
        data(label, price, quantity, production_date) {};
    Product(ProductData data): data(data) {};
    virtual ~Product() = default;

    // Getters
    string GetLabel() const;
    int GetPrice() const;
    double GetQuantity() const;
    string GetProductionDateString() const;
    tm GetProductionDate() const;
    virtual string GetType() const = 0;

    // Setters
    void ChangePrice(int price);
    virtual bool Buy(double quantity);
    virtual bool Restock(double quantity);

    virtual double CanBuy(double quantity) const = 0;
    virtual double CanRestock(double quantity) const = 0;
    virtual bool IsExpired() const = 0;
};

#endif // PRODUCT_H