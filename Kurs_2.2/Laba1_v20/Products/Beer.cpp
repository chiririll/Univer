#include "Beer.h"

string Beer::GetType() const {
    return "beer";
}

double Beer::CanBuy(double quantity) const {
    return quantity <= GetQuantity() ? quantity : GetQuantity();
}

double Beer::CanRestock(double quantity) const {
    if (GetQuantity() + quantity > warehouse_size)
        return warehouse_size - GetQuantity();
    else 
        return quantity;
}

bool Beer::IsExpired() const {
    return std::time(NULL) > expiration_date;
}