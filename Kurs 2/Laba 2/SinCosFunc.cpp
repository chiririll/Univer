#include <cmath>
#include "SinCosFunc.hh"

/* Constructors */
SinCosFunc::SinCosFunc() : SinCosFunc(1, 1, 1) {}
SinCosFunc::SinCosFunc(double a) : SinCosFunc(a, 1, 1) {}
SinCosFunc::SinCosFunc(double a, double b) : SinCosFunc(a, b, 1) {}
SinCosFunc::SinCosFunc(double a, double b, double c) : a(a), b(b), c(c) {}
/* ============ */

/* Operators */
double SinCosFunc::operator() (double x) const {
    return get(x);
}
/* ========= */

/* Getters & setters */
// void SinCosFunc::set_a(double a) {this->a = a;}
// void SinCosFunc::set_b(double b) {this->b = b;}
// void SinCosFunc::set_c(double c) {this->c = c;}

double SinCosFunc::get_a() const {return this->a;}
double SinCosFunc::get_b() const {return this->b;}
double SinCosFunc::get_c() const {return this->c;}
/* ================= */

/* Strings */
string SinCosFunc::get_function_as_string() const {
    char str[80];
    sprintf(str, "a * sin(b*x), x < 0; cos(c*x) - 1, x >= 0 \tWhere a = %.2f, b = %.2f, c = %.2f", this->a, this->b, this->c);
    return str;
}

string SinCosFunc::get_function_as_string(double x) const {
    char str[50];
    if (x < 0)
        sprintf(str, "a * sin(b*x) = %.2f * sin(%.2f * %.2f) = %.2f", this->a, this->b, x, get(x));
    else
        sprintf(str, "cos(c*x) - 1 = cos(%.2f * %.2f) - 1 = %.2f", this->c, x, get(x));
    return str;
}
/* ======= */

/* Values */
double SinCosFunc::get(double x) const {
    return x < 0 ? this->a * sin(this->b * x) : cos(this->c * x) - 1;
}

double SinCosFunc::get_argument_of_value(double f) const {
    if (f >= -2 && f <= -1)
        return acos(f + 1) / this->c;
    if (f >= 0 && f <= 1)
        return asin(f / this->a) / this->b;
    return 404;
}
/* ====== */