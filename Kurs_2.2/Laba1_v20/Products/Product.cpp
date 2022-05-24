#include "Product.h"

std::string Product::GetLabel() const {
    return label;
}

int Product::GetPrice() const {
    return price;
}

double Product::GetQuantity() const {
    return quantity;
}

void Product::ChangePrice(int price) {
    this->price = price;
}

bool Product::Buy(double quantity) {
    if (this->CanBuy(quantity) != quantity)
        return false;

    this->quantity -= quantity;
    return true;
}

bool Product::Restock(double quantity) {
    if (this->CanRestock(quantity) != quantity)
        return false;

    this->quantity += quantity;
    return true;
}
