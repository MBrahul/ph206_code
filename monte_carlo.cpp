#include<iostream>
using namespace std;

double f(double x){
    // double x  = X-2;
    return 2*x + 3*x*x + 5*x*x*x;
}


void monte_carlo(){
    int lower_limit = 2;
    int upper_limit = 3;
  
    int n =1000;
    
    double h = 1/n;
    double res = 0;
    for(int i=1;i<=n;i++){
       double r = ((double)rand()/(RAND_MAX));
    //   double r = i/n;
       res+=f((upper_limit-lower_limit)*r+lower_limit);
    // res += f(r);
    }
    res=res/n;
    cout<<res<<endl;
}

int main(){
    
    monte_carlo();
cout<<endl<<(81*5)/4;
    return 0;
}