#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

using std::string;

class Product {
private:
    string label;
    int price;
    double quantity;

public:
    Product(string label, int price, double quantity): 
        label(label), price(price), quantity(quantity) {};
    virtual ~Product();

    // Getters
    string GetLabel() const;
    int GetPrice() const;
    double GetQuantity() const;
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