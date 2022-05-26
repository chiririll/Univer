#include <vector>
#include <string>

#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

class ErrorHandler {
private:
    std::string prefix;
    std::vector<std::string> errors;

protected:
    void PushError(std::string error);
    std::string GetPrefix() const;

public:
    ErrorHandler(): prefix("") {};
    ErrorHandler(const std::string &prefix): prefix(prefix) {};
    virtual ~ErrorHandler();

    std::string GetError();
};

#endif // ERROR_HANDLER_H
