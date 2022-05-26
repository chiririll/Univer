#include "List.h"

void List::Execute(std::vector<std::string> args) {
    using namespace std;

    string type;
    if (args.size() > 1)
        type = args[1];
    
    cout << "List of " << (type.empty() ? "products" : type) << ":" << endl;

    // vector<string> header = {"Id", "Type", "Label", "Price", "Quantity", "Production date"};
    
    cout << endl << "Id\t | Type\t | Label\t | Price\t | Quantity\t | Production date" << endl;
    cout << "===================================================================================" << endl;
    // TODO: Display addition
    for (Product* product : *products) {
        if (type.empty() || product->GetType() == type)
            cout << product->GetId() << "\t | " 
                << product->GetType() << "\t | " 
                << product->GetLabel() << "\t | " 
                << product->GetPrice() << "\t\t | " 
                << product->GetQuantity() << "\t\t | " 
                << product->GetProductionDateString() << "\t" 
                << endl;
    }
}

std::string List::GetWord() const {
    return "list";
}

std::string List::GetDescription() const {
    return "Displays list of products";
}

std::string List::GetArgs() const {
    return "<type>";
}
