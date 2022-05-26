#include "List.h"


void List::Execute(std::vector<std::string> args) {
    using namespace std;

    cout << "List of products:" << endl;

    cout << endl << "Type\t | Label\t | Price\t | Quantity\t | Production date" << endl;
    cout << "===========================================================================" << endl;
    for (Product* product : *products)
        cout << product->GetType() << "\t | " 
             << product->GetLabel() << "\t | " 
             << product->GetPrice() << "\t\t | " 
             << product->GetQuantity() << "\t\t | " 
             << product->GetProductionDateString() << "\t" 
             << endl;
}

std::string List::GetWord() const {
    return "list";
}

std::string List::GetDescription() const {
    return "Displays list of products";
}

std::string List::GetArgs() const {
    return "";
}
