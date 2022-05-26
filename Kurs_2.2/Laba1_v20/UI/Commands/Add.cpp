#include "Add.h"


void Add::Execute(std::vector<std::string> args) {
    using namespace std;

    vector<string> fields;
    fields.insert(fields.begin(), args.begin() + 1, args.end());
    
    ProductCreator creator;
    Product* product = creator.CreateProduct(fields);
    
    if (product == NULL)
        cout << "Can't create product: " << creator.GetError() << endl;
    else {
        cout << "Product has been created" << endl;
        products->push_back(product);
    }
}

std::string Add::GetWord() const {
    return "add";
}

std::string Add::GetDescription() const {
    return "Adds product to list";
}

std::string Add::GetArgs() const {
    return "<type> <label> <price> <quantity> <production date> <type specific params>";
}
