#include "Remove.h"


void Remove::Execute(std::vector<std::string> args) {
    using namespace std;

    if (args.size() < 2) {
        cout << "You need to provide product id." << endl;
        return;
    }

    int id;
    string error = str_to_int("Id", args[1], id);
    if (!error.empty()) {
        cout << error << endl;
        return;
    }

    for (int i = 0; i < products->size(); i++)
        if (products->at(i)->GetId() == id) {
            delete products->at(i);
            products->erase(products->begin() + i);
            cout << "Product has been deleted.";
            return;
        }
    cout << "Can't find product with id '" << id << "'." << endl;
}

std::string Remove::GetWord() const {
    return "remove";
}

std::string Remove::GetDescription() const {
    return "Removes product from list";
}

std::string Remove::GetArgs() const {
    return "<id>";
}
