#include <cmath>
#include "SinCosFunc.hh"

/* Constructors */
SinCosFunc::SinCosFunc() : SinCosFunc(1, 1, 1) {}
SinCosFunc::SinCosFunc(double a) : SinCosFunc(a, 1, 1) {}
SinCosFunc::SinCosFunc(double a, double b) : SinCosFunc(a, b, 1) {}
SinCosFunc::SinCosFunc(double a, double b, double c) : a(a), b(b), c(c) {}
/* ============ */

/* Strings */
string SinCosFunc::get_function_as_string() const {
    char str[50];
    sprintf(str, "x < 0 ? %.2f * sin(%.2f * x) : cos(%.2f * x)", this->a, this->b, this->c);
    return str;
}

string SinCosFunc::get_function_as_string(double x) const {
    char str[50];
    if (x < 0)
        sprintf(str, "%.2f * sin(%.2f * %.2f) = %.2f", this->a, this->b, x, get(x));
    else
        sprintf(str, "cos(%.2f * %.2f) = %.2f", this->c, x, get(x));
    return str;
}
/* ======= */

/* Values */
double SinCosFunc::get(double x) const {
    return get(x, this->a, this->b, this->c);
}

double SinCosFunc::get(double x, double a, double b, double c) const {
    return x < 0 ? a * sin(b * x) : cos(c * x);
}

double SinCosFunc::get_argument_of_value(double val) const {
    // TODO
    return 0;
}
/* ====== */

/* Operators */
double SinCosFunc::operator() (double x) {
    return get(x, this->a, this->b, this->c);
}
/* ========= */
