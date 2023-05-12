// C++ program for implementation of Bisection Method for
// solving equations
#include <iostream>
using namespace std;
#define EPSILON 0.001
#define h 0.00000001

// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2 + 2
double f(double x)
{
    return x * x * x -  x * x + 2;
}

double derivative(double x){
    double dt = (f(x+h)-f(x))/h;
    return dt;
}

// Prints root of func(x) with error of EPSILON
void bisection(double a, double b)
{

    if (f(a) * f(b) < 0)
    {
        double c = (a + b) / 2;
        if ((b - a) >= EPSILON)
        {
            if (f(c) == 0)
            {
                cout << "root is:" << c << " (without error)" << endl;
            }
            else if (f(a) * f(c) < 0)
            {
                bisection(a, c);
            }
            else
            {
                bisection(c, b);
            }
        }
        else
        {
            cout << "root is:" << c << endl;
        }
    }

    else{

        cout<<"The assumptions not statisfied"<<endl;
    }
}

// Driver program to test above function
int main()
{
    // Initial values assumed
    double a = -200, b = 300;
    bisection(a ,b);
    double c =2;
    cout<<"Derivative at "<<c<<" : "<<derivative(c)<<endl;
    return 0;
}
