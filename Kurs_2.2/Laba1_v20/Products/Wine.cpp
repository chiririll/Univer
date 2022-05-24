#include "Wine.h"

string Wine::GetType() const {
    return "wine";
}

double Wine::CanBuy(double quantity) const {
    return ceil(quantity) <= GetQuantity() ? ceil(quantity) : floor(GetQuantity());
}

double Wine::CanRestock(double quantity) const {
    return quantity;
}

bool Wine::IsExpired() const {
    return false;
}
