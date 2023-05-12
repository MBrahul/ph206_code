#include <iostream>
#include <math.h>
using namespace std;
#define Max_iteration 100000

int iteration = 0;

double f(double x)
{
    return pow(x, 3) - pow(x, 2) + 2;
}
void false_position_method(double a, double b)
{
    if (f(a) * f(b) < 0)
    {
        double c = a;
        for (int i = 0; i < Max_iteration; i++)
        {
            c = (a * f(b) - b * f(a)) / (f(b) - f(a));
            if (f(c) == 0)
            {
                break;
            }
            else if (f(a) * f(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }

        cout << "root is " << c << endl;
    }

    else
    {
        cout << "The given input is not satisfied the assumptions" << endl;
    }
}
int main()
{
    double a = -200, b = 300;
    false_position_method(a, b);
}