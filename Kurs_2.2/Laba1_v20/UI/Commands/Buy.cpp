#include "Buy.h"

void Buy::Execute(std::vector<std::string> args) {
    using namespace std;


    // Id
    if (args.size() < 2) {
        cout << "You need to provide product id." << endl; return;
    }
    int id;
    string error = str_to_int("Id", args[1], id);
    if (!error.empty()) { 
        cout << error << endl; return;
    }

    // Amount
    double amount = 1;
    if (args.size() > 2) {
        error = str_to_double("Amount", args[2], amount);
        if (!error.empty()) {
            cout << error << endl; return;
        }
    }

    // Finding product
    Product* target = NULL;
    for (Product* p : *products)
        if (p->GetId() == id) {
            target = p; break;
        }
    if (target == NULL) {
        cout << "Can't find product with id '" << id << "'." << endl;
        return;
    }

    // Buying product
    double can_buy = target->CanBuy(amount);
    
    string inp;
    if (can_buy != amount) {    
        cout << "You can't buy '" << amount << "' of " << target->GetType() 
            << ". Would you like to buy '" << can_buy << "' instead? (Y/n) ";
        getline(cin, inp);
        if (inp == "n" || inp == "N")
            return;
    }

    int cost = can_buy * target->GetPrice();
    cout << "Total cost is '" << cost << "'. Continue? (Y/n) ";
    getline(cin, inp);
    if (inp == "n" || inp == "N")
        return;

    if (!target->Buy(can_buy)) {
        cout << "Unknown error." << endl;
        return;
    }

    earnings += cost;
    cout << "Total earnings: " << earnings << endl;
}

std::string Buy::GetWord() const {
    return "buy";
}

std::string Buy::GetDescription() const {
    return "Buys product";
}

std::string Buy::GetArgs() const {
    return "<id> <amount>";
}
