#include "Clear.h"


void Clear::Execute(std::vector<std::string> args) {
    using namespace std;

    bool agreed = false;
    for (string arg : args)
        agreed = agreed || arg == "-y";

    if (!agreed) {
        string choice;
        cout << "Are you sure want to clear " << products->size() << " loaded products? (y/N) ";
        getline(cin, choice);
        if (choice == "y" || choice == "Y")
            agreed = true;
        else
            return;
    }
    
    products->clear();
    cout << "Products cleared successfully!" << endl;
}

std::string Clear::GetWord() const {
    return "clear";
}

std::string Clear::GetDescription() const {
    return "Clear product list";
}

std::string Clear::GetArgs() const {
    return "<-y agree>";
}
