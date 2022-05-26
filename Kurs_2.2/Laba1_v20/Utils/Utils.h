#include <string>

using std::string;

#ifndef UTILS_H
#define UTILS_H

template <typename T, typename F>
string try_to_cast(const string &field_name, const string &value, T& result, F function);
// Integers (stoi, stol, stoll)
template <typename T>
string try_to_cast(const string &field_name, const string &value, T& result, T(*function)(const string&, std::size_t*, int));
// Floating (stod, stof, stold)
template <typename T>
string try_to_cast(const string &field_name, const string &value, T& result, T(*function)(const string&, std::size_t*));

#endif // UTILS_H