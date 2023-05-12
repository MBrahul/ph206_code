
#include <iostream>
#include <math.h>
using namespace std;
#define EPSILON 0.001

int iteration = 0;

double f(double x)
{
    return x * x * x - x * x + 2;
}

double df(double x)
{
    return 3 * pow(x, 2) - 2 * x;
}

void newtonRaphson(double x)
{
    double h = f(x) / df(x);
    while (abs(h) > EPSILON)
    {

        h = f(x) / df(x);
        x = x - h;

        iteration++;
    }

    cout << "The value of the root is : " << x << endl;
    cout << "iterations : " << iteration << endl;
}

int main()
{
    newtonRaphson(-20);
    return 0;
}
