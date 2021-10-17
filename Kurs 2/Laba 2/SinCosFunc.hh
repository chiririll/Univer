#include <string>

#ifndef SINCOSFUNC_H
#define SINCOSFUNC_H

using namespace std;

class SinCosFunc 
{
private:
    const double a, b, c;

public:
    // Constructors
    SinCosFunc();
    SinCosFunc(double a);
    SinCosFunc(double a, double b);
    SinCosFunc(double a, double b, double c);
    
    // Values
    double get(double x) const;
    double get(double x, double a, double b, double c) const;
    double get_argument_of_value(double x) const;
    
    // Strings
    string get_function_as_string() const;
    string get_function_as_string(double x) const;

    // Operators
    double operator() (double x);
};

#include "SinCosFunc.cpp"
#endif