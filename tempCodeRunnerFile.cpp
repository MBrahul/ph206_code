#include<iostream>
using namespace std;

int main(){


  int arr[] ={1,2,3,4,5};
  int d =2;
  for(int i =0;i<d;d++){
    int temp = arr[5-1];
    for(int j=0;j<5;j++){
        if(i<d){
            arr[5-1+i]=arr[i];
        }
        else{
            if(i==5-1){
                arr[i-1]=temp;
            }
            else{
                arr[i-1]=arr[i];
            }
           
        }
    }
  }
for(int i =0;i<5;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}