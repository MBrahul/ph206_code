#include<iostream>
using namespace std;

#define n 10

double f(double x){
    return 2*x + 3*x*x + 5*x*x*x;
}

void simpson(double lower_limit , double upper_limit){

double x[n+1] , fx[n+1];
double h = (upper_limit-lower_limit)/n;

for(int i =0;i<=n;i++){
    x[i]= lower_limit + i*h;
    fx[i]=f(x[i]);
}

double res =0;
for(int i =0;i<=n;i++){
    if(i==0 || i==n){
        res+=fx[i];
    }
    else if(i%2==0){
        res+=2*fx[i];
    }
    else{
         res+=4*fx[i];
    }
}

res = res*h/3;
cout<<res<<endl;
}

int main(){

simpson(2,3);

    return 0;
}