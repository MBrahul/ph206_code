#include<iostream>
#include<vector>
using namespace std;



void rotate(int *input , int n , int d)
{
    vector<int> v;
    for(int i = 0;i<d;i++){
        v.push_back(input[i]);
    }
    for(int i = d;i<n;i++){
        input[i-d]=input[i];
    }
    for(int i = n-d;i<n;i++){
        input[i]=v[i-n+d];
    }

    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
}

int main(){

//    int arr []={1,2,3,4,5,6,7,8,0};
//    rotate(arr , 9, 1);

    return 0;


}