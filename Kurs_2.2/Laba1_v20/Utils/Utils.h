#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using std::string;
using std::tm;

#ifndef UTILS_H
#define UTILS_H

// Parsing numbers
template <typename T, typename F>
string try_to_cast(const string &field_name, const string &value, T& result, F function);
// Integers (stoi, stol, stoll)
template <typename T>
string try_to_cast(const string &field_name, const string &value, T& result, T(*function)(const string&, std::size_t*, int));
// Floating (stod, stof, stold)
template <typename T>
string try_to_cast(const string &field_name, const string &value, T& result, T(*function)(const string&, std::size_t*));

// Parsing date
string parse_date(const string &field_name, const string &value, tm& result);

#endif // UTILS_H