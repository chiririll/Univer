#include "ErrorHandler.h"

void ErrorHandler::PushError(string error) {
    errors.push_back(error);
}

string ErrorHandler::GetPrefix() const {
    return prefix;
}

string ErrorHandler::GetError() {
    if (errors.empty())
        return "";
    if (errors.size() == 1) {
        string error = errors.back();
        errors.pop_back();
        return error;
    }

    string errors_list = "\n";
    for (const string &err : errors) {
        errors_list += prefix + "- " + err + "\n";
    }
    
    errors.clear();
    return errors_list;
}
