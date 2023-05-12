#include<iostream>
using namespace std;

void fn(int n, int count){
    if(n>0){
        if(n%10==0){
            fn(n/10,count+1);
        }
        else{
            fn(n/10,count);
        }
    }
    else{
        cout<<count<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    fn(n,0);
    return 0;

}