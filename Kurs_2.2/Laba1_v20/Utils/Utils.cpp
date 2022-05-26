#include "Utils.h"

template <typename T, typename F>
string try_to_cast(const string &field_name, const string &value, T& result, F function) {
    try
        result = function(value);
    catch (std::invalid_argument const& ex)
        return "Invalid " + field_name ": " + value;
    catch (std::out_of_range const& ex)
        return field_name + " is too big: " + value;
    return "";
}

template <typename T>
string try_to_cast(const string &field_name, const string &value, T& result, T(*function)(const string&, std::size_t*, int)) {
    return try_to_cast(field_name, value, result, function);
}

template <typename T>
string try_to_cast(const string &field_name, const string &value, T& result, T(*function)(const string&, std::size_t*)) {
    return try_to_cast(field_name, value, result, function);
}

string parse_date(const string &field_name, const string &value, tm& result) {
    std::istringstream ss(value);
    ss >> std::get_time(&result, "%Y-%m-%d");
    if (ss.fail())
        return "Invalid " + field_name + ": " + value;
    return "";
}