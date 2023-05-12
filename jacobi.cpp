#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

#define N 3

void jacobi(double A[N][N]){
    int a=0,b=1;
    double max=abs(A[a][b]);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j&&j>i&&max<abs(A[i][j])){
                max=abs(A[i][j]);
                a=i;
                b=j;
            }
        }
    }
   
   // printf("%d %d\n",a,b); 
    double angle =(atan(2*A[a][b]/abs(A[b][b]-A[a][a])))/2;
    double B[N][N];
    double c =cos(angle),s=sin(angle);
    memset(B,0,sizeof(B));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==a&&j==a){
                 B[i][j]=c*c*A[a][a]-2*s*c*A[a][b]+s*s*A[b][b];
                ;
            }
            else if(i==b&&j==b){
                 B[i][j]=s*s*A[a][a]+2*s*c*A[a][b]+c*c*A[b][b];
                 
            }
            else if((i==a&&j==b)||(i==b&&j==a)){
                    //B[i][j]=(c*c-s*s)*A[i][j] + s*c*(A[i][i]-A[j][j]);
                    B[i][j]=0;
            }
            else if((i==a)&&(j!=a&&j!=b)){
                        B[i][j]=c*A[a][j]-s*A[b][j];
            }
            else if((i!=a&&i!=b)&&(j==a)){
                 B[i][j]=c*A[a][i]-s*A[b][i];
            }
            else if((i==b)&&(j!=a&&j!=b)){
                        B[i][j]=s*A[a][j]+c*A[b][j];
            }
            else if((i!=a&&i!=b)&&(j==b)){
                   B[i][j]=s*A[a][i]+c*A[b][i];
            }
            else if((i!=a&&i!=b)&&(j!=a&&j!=b)){
                B[i][j]=A[i][j];
            }
        }
    }
   
    memcpy(A,B,9*sizeof(double));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%4.3lf ",A[i][j]);
           
    }
    cout<<endl;
    }

}


int main(){

 //double A[N][N]={{1,pow(2,0.5),2},{pow(2,0.5),3,pow(2,0.5)},{2,pow(2,0.5),1}};
   double A[N][N]={{2,1,0},{1,4,1},{0,1,4}};
  
  
  while(true){
    int a=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j&&j>i&&abs(A[i][j])>0.000001){
                a++;
            }
          }
        }
       
        cout<<a;
        cout<<endl;
        if(a==0){
            break;
        }
        else{
            jacobi(A);
        }
    }

     return 0;
  }
  
   
