#include "Vodka.h"

string Vodka::GetType() const {
    return "vodka";
}

map<string, string> Vodka::GetAddition() const {
    map<string, string> fields;

    fields["warehouse_size"] = std::to_string(warehouse_size);
    
    return fields;
}

double Vodka::CanBuy(double quantity) const {
    double valid_amount = ((int)quantity / 6 + ((int)quantity % 6 ? 1 : 0)) * 6;
    return valid_amount <= GetQuantity() ? valid_amount : ((int)GetQuantity() / 6) * 6;
}

double Vodka::CanRestock(double quantity) const {
    double valid_amount = ((int)quantity / 6 + ((int)quantity % 6 ? 1 : 0)) * 6;
    if (GetQuantity() + valid_amount > warehouse_size)
        return ((int)(warehouse_size - GetQuantity()) / 6) * 6;
    else 
        return valid_amount;
}

bool Vodka::IsExpired() const {
    return false;
}