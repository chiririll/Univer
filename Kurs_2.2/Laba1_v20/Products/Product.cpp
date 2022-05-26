#include "Product.h"

string Product::DateToString(const tm &date) const {
    char buffer[11];
    strftime(buffer, 11, "%Y-%m-%d", &date);
    return string(buffer);
}

int Product::GetId() const {
    return data.id;
}

string Product::GetLabel() const {
    return data.label;
}

int Product::GetPrice() const {
    return data.price;
}

double Product::GetQuantity() const {
    return data.quantity;
}

string Product::GetProductionDateString() const {
    return DateToString(data.production_date);
}

tm Product::GetProductionDate() const {
    return data.production_date;
}

void Product::SetId(int id) {
    data.id = id;
}

void Product::ChangePrice(int price) {
    data.price = price;
}

bool Product::Buy(double quantity) {
    if (CanBuy(quantity) != quantity)
        return false;

    data.quantity -= quantity;
    return true;
}

bool Product::Restock(double quantity) {
    if (CanRestock(quantity) != quantity)
        return false;

    data.quantity += quantity;
    return true;
}
