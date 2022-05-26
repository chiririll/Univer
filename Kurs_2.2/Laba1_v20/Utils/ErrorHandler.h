#include <vector>
#include <string>

using std::string;

#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

class ErrorHandler {
private:
    string prefix;
    std::vector<string> errors;

public:
    ErrorHandler(): prefix("") {};
    ErrorHandler(const string &prefix): prefix(prefix) {};
    virtual ~ErrorHandler() = default;

    string GetPrefix() const;
    void PushError(string error);
    string GetError();
};

#endif // ERROR_HANDLER_H
