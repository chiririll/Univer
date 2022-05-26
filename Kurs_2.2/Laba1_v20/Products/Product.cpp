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
