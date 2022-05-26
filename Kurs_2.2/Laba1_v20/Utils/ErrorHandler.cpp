#include "ErrorHandler.h"

void ErrorHandler::PushError(std::string error) {
    errors.push_back(error);
}

std::string ErrorHandler::GetPrefix() const {
    return prefix;
}

std::string ErrorHandler::GetError() {
    if (errors.empty())
        return "";
    if (errors.size() == 1) {
        std::string error = errors.back();
        errors.pop_back();
        return error;
    }

    std::string errors_list = "\n";
    for (const std::string &err : errors) {
        errors_list += prefix + "- " + err + "\n";
    }
    
    errors.clear();
    return errors_list;
}
