#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using std::string;
using std::tm;

#ifndef UTILS_H
#define UTILS_H

// Parsing numbers
string str_to_int(const string &field_name, const string &value, int& result);
string str_to_double(const string &field_name, const string &value, double& result);

// Parsing date
string parse_date(const string &field_name, const string &value, tm& result);

#endif // UTILS_H