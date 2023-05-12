#include<iostream>
#include<vector>
using namespace std;


void smaxCharInString(string str){
    vector<int> asciValue(58,0);
    for(int i=0;i<str.length();i++){
        int a=str[i]-65;
        asciValue[a]++;
    }

    int max = asciValue[0];
    int a=0;
    for(int i =0;i<asciValue.size();i++){
        if(max<asciValue[i]){
            max= asciValue[i];
            a=i;
        }
    }

    char ch = a+65;
   cout<<ch<<endl;

}

int main(){
string str;
cin>>str;
smaxCharInString(str);
return 0;

}