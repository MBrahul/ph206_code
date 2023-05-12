#include<iostream>
#include<cmath>
using namespace std;

#define N 3

void printMat(double mat[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
           printf(" %4.2lf ",mat[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}
 void luDecomposition(double mat[N][N]){
    double lower[N][N];
    double upper[N][N];
    memset(lower,0,sizeof(lower));
    memset(lower,0,sizeof(upper));

    for(int i=0;i<N;i++){
        // upper matrix
        for(int k=i;k<N;k++){
            double sum =0;
            for(int j=0;j<i;j++){
                sum+=(lower[i][j]*upper[j][k]);
            }
            upper[i][k]=mat[i][k]-sum;
        }

        //lower matrix
        for(int k=i;k<N;k++){
           if(i==k){
                lower[i][i]=1;
           }
           else{
             double sum=0;
            for(int j=0;j<i;j++){
                sum+=(lower[k][j]*upper[j][i]);
            }
            lower[k][i]=(mat[k][i]-sum)/upper[i][i];
           }
        }
    }
    printMat(lower);
    printMat(upper);

    // LUX= B UX=Y
    //calculating Y
    double B[N]={1,5,10};
    double Y[N];
    for(int i=0;i<N;i++){
        Y[i]=B[i];
        for(int j=i-1;j>=0;j--){
            Y[i]=Y[i]-lower[i][j]*Y[j];
        }
        Y[i]=Y[i]/lower[i][i];
    }
    double X[N];
    printf("solutions are:\n");
    for(int i=N-1;i>=0;i--){
        X[i]=Y[i];
        for(int j=i+1;j<N;j++){
            X[i]=X[i]-upper[i][j]*X[j];
        }
        X[i]=X[i]/upper[i][i];
        printf("%4.3lf\n",X[i]);
    }
    
 }

int main(){
   double mat[N][N]={ { 1, 1, 1 }, { 3, 1, -3 }, { 1, -2, -5 } };
   luDecomposition(mat);

    return 0;
}