#include "Utils.h"

string str_to_int(const string &field_name, const string &value, int& result) {
    try {
        result = stoi(value);
    } catch (std::invalid_argument const& ex) {
        return "Invalid " + field_name + ": " + value;
    } catch (std::out_of_range const& ex) {
        return field_name + " is too big: " + value;
    }
    return "";
}

string str_to_double(const string &field_name, const string &value, double& result) {
    try {
        result = stod(value);
    } catch (std::invalid_argument const& ex) {
        return "Invalid " + field_name + ": " + value;
    } catch (std::out_of_range const& ex) {
        return field_name + " is too big: " + value;
    }
    return "";
}

string parse_date(const string &field_name, const string &value, tm& result) {
    std::istringstream ss(value);
    ss >> std::get_time(&result, "%Y-%m-%d");
    if (ss.fail())
        return "Invalid " + field_name + ": " + value;
    return "";
}