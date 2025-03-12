#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double result = 1.0;
    double term = 1.0;
    int n = 1;
    for (int i = 1; i <= 10; i++) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        result += term;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result = x;
    double term = x;
    int n = 1;
    for (int i = 1; i <= 10; i++) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        result += term;
    }
    return result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double guess = x;
    double epsilon = 1e-6;
    while (fabs(guess * guess - x) > epsilon) {
        guess = (guess + x / guess) / 2;
    }
    return guess;
}
