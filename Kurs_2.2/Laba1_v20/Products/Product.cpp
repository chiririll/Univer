#include "Product.h"

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
    char buffer[12];
    strftime(buffer, 12, "%Y-%m-%d", &data.production_date);
    return string(buffer);
}

tm Product::GetProductionDate() const {
    return data.production_date;
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
