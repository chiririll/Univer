#include "FixId.h"

void FixId::Execute(std::vector<std::string> args) {
    using namespace std;

    for (int i = 0; i < products->size(); i++)
        products->at(i)->SetId(i);

    cout << "Ids reordered" << endl;
}

std::string FixId::GetWord() const {
    return "fixid";
}

std::string FixId::GetDescription() const {
    return "Reorder ids to aviod conflicts";
}

std::string FixId::GetArgs() const {
    return "";
}
