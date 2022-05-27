#include "Earnings.h"

void Earnings::Execute(std::vector<std::string> args) {
    using namespace std;
    cout << "Total earnings: " << earnings << endl;
}

std::string Earnings::GetWord() const {
    return "earnings";
}

std::string Earnings::GetDescription() const {
    return "Displays total earnings";
}

std::string Earnings::GetArgs() const {
    return "";
}
