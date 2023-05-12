#include<iostream>
#include<cstring>
#include<math.h>
#include<vector>
using namespace std;

#define N 3

void multiply(double A[N][N],double B[N][N],bool first){
    double C[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            double a=0;
            for(int k=0;k<N;k++){
                    a+=A[i][k]*B[k][j];
            }
            C[i][j]=a;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(first){
               A[i][j]=C[i][j]; 
            }
          else{
             B[i][j]=C[i][j];
          }
      }            
    }

     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        //   A[i][j]=C[i][j];
        printf("%4.3lf ",A[i][j]);
        }    
        cout<<endl;
    }
  cout<<endl;

}

void givensMethod(){}

double f(double x,double A[N][N])
{
    return (A[2][2]-x)*(((A[1][1]-x)*(A[0][0]-x))-A[0][1]*A[1][0]);
}

void bisection(double a, double b,double A[N][N])
{

    if (f(a,A) * f(b,A) < 0)
    {
        double c = (a + b) / 2;
        if ((b - a) >= 0.0001)
        {
            if (f(c,A) == 0)
            {
                cout << "root is:" << c << " (without error)" << endl;
            }
            else if (f(a,A) * f(c,A) < 0)
            {
                bisection(a, c,A);
            }
            else
            {
                bisection(c, b,A);
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

int main(){
    double A[N][N]={{3,1,1},{1,3,2},{1,2,3}};
     
    double s,c;
    double angle = atan(-A[0][2]/A[0][1]);
    s=sin(angle);
    c=cos(angle);
    double r[N][N]={{c,0,s},{0,1,0},{-s,0,c}};
    double rInverse[N][N]={{c,0,-s},{0,1,0},{s,0,c}};

    multiply(rInverse,A,false);
    multiply(A,r,true);
    bisection(0,10,A);
   
    //   vector<string> v;
    //   v.push_back("rahul");
    // std::cout<<v[0];
    
   // double x;
    //double chEquation = (A[2][2]-x)*(((A[1][1]-x)*(A[0][0]-x))-A[0][1]*A[1][0]);
    //cout<<chEquation;
    
}
