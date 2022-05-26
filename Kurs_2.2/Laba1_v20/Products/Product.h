#include <string>
#include <map>
#include <ctime>

#ifndef PRODUCT_H
#define PRODUCT_H

using std::string;
using std::map;
using std::tm;

struct ProductData {
    int id;
    string label;
    int price;
    double quantity;
    tm production_date;

    ProductData() = default;
    ProductData(int id, string label, int price, double quantity, tm producrion_date): 
        id(id), label(label), price(price), quantity(quantity), production_date(production_date) {};
};

class Product {
private:
    ProductData data;

protected:
    string DateToString(const tm &date) const;

public:
    Product(int id, string label, int price, double quantity, tm production_date): 
        data(id, label, price, quantity, production_date) {};
    Product(ProductData data): data(data) {};
    virtual ~Product() = default;

    // Getters
    int GetId() const;
    string GetLabel() const;
    int GetPrice() const;
    double GetQuantity() const;
    string GetProductionDateString() const;
    tm GetProductionDate() const;
    virtual string GetType() const = 0;
    virtual map<string, string> GetAddition() const = 0;

    // Setters
    void SetId(int id);
    void ChangePrice(int price);
    virtual bool Buy(double quantity);
    virtual bool Restock(double quantity);

    virtual double CanBuy(double quantity) const = 0;
    virtual double CanRestock(double quantity) const = 0;
    virtual bool IsExpired() const = 0;
};

#endif // PRODUCT_H