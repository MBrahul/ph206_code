#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define N 2

void multiply(double A[N][N], double X[N]){
    double newX[N];
    memset(newX,0,sizeof(newX));
    for(int i=0;i<N;i++){
        double a=0;
        for(int j=0;j<N;j++){
            a+=A[i][j]*X[j];
        }
        newX[i]=a;
        // printf("%4.2lf ",newX[i]);
    }
  for(int i=0;i<N;i++){
    X[i]=newX[i];
  }
}

double egenvalue(double X[N],bool b){
    double max = X[0];

    for(int i=0;i<N;i++){
        if(X[i]>max)max=X[i];
    }
   if(b) printf("Egenvalue: %4.3lf\n",max);
    if(b)  printf("Egenvector\n");
    for(int i=0;i<N;i++){
       X[i]=X[i]/max;
        if(b) printf("%4.3lf\n",X[i]);
    }
    cout<<endl;

return max;

}

void powerMethod(double A[N][N], double X[N]){
    double lastEgenValue = egenvalue(X,false);
    // cout<<egenValue<<endl;
    multiply(A,X);
    double newEgenValue = egenvalue(X,true);
   while((abs(newEgenValue-lastEgenValue))>0.002){
        // printf("previos data\n");
        // printf("last-%4.3lf\n",lastEgenValue);
        // printf("new-%4.3lf\n",newEgenValue);
        multiply(A,X);
        lastEgenValue= newEgenValue;
        newEgenValue=egenvalue(X,true);
        // printf("new data\n");
        // printf("new-%4.3lf\n",newEgenValue);
        // printf("last-%4.3lf\n",lastEgenValue);
        //  cout<<endl;
   }
  
   

}

int main(){
  double A[N][N]={{5,4},
                  {1,2}};
  double X[N]={1,1};

 powerMethod(A,X);
  return 0;              
}