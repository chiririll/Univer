#include "Vodka.h"

string Vodka::GetType() const {
    return "vodka";
}

double Vodka::CanBuy(double quantity) const {
    double valid_amount = ((int)quantity / 6) * 6;
    return valid_amount <= GetQuantity() ? valid_amount : ((int)GetQuantity() / 6) * 6;
}

double Vodka::CanRestock(double quantity) const {
    double valid_amount = ((int)quantity / 6) * 6;
    if (GetQuantity() + valid_amount > warehouse_size)
        return ((int)(warehouse_size - GetQuantity()) / 6) * 6;
    else 
        return valid_amount;
}

bool Vodka::IsExpired() const {
    return false;
}