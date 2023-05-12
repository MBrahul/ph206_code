#include <iostream>
#include <math.h>
#define E 0.0001
using namespace std;

double f(double x)
{
    // we are taking equation as x^3+x-1
    double f = pow(x, 3) + x - 1;
    return f;
}

void secent(double x1, double x2)
{
    if (f(x1) * f(x2) < 0)
    {
        double xm;
        int iteration = 0;
        double x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        do
        {
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            x1 = x2;
            x2 = x0;
            iteration++;
            if (f(x0) == 0)
                break;

            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

        } while (fabs(xm - x0) >= E);
        cout << x0 << endl;
        cout << iteration << endl;
    }
    else
    {
    }
}

int main()
{

    secent(0, 1);
    return 0;
}