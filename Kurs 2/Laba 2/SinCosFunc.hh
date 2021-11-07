#include <string>

#ifndef SINCOSFUNC_H
#define SINCOSFUNC_H

using namespace std;

class SinCosFunc 
{
private:
    double a, b, c;
    
    // Values
    double get(double x) const;

public:
    // Constructors
    SinCosFunc();
    SinCosFunc(double a);
    SinCosFunc(double a, double b);
    SinCosFunc(double a, double b, double c);
    
    // Operators
    double operator() (double x) const;

    // Setters
    void set_a(double a);
    void set_b(double b);
    void set_c(double c);

    // Getters
    double get_a() const;
    double get_b() const;
    double get_c() const;

    // Values
    double get_argument_of_value(double x) const;
    
    // Strings
    string get_function_as_string() const;
    string get_function_as_string(double x) const;
};

#include "SinCosFunc.cpp"
#endif