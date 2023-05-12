#include<iostream>
using namespace std;


    string reverse(string s){
        char ch;
        //abcd
        string s1 = s;
        for(int i =0;i<s.length()/2;i++){
                ch=s1[i];
                s1[i]=s1[s1.length()-i-1];
                s1[s1.length()-i-1]=ch;
        }
        return s1;
    }

    bool isPalindromic(string s){
        string s2 = reverse(s);
            if(s==s2){
               return true;
            }
           return false;
    }
    string longestPalindrome(string s) {
       string palindrome="";
        for(int i=0;i<s.length();i++){
            string str="";
            str+=s[i];
            cout<<str<<endl;
            for(int j=i+1;j<s.length();j++){
                str+=s[j];
                if(isPalindromic(str)){
                   palindrome=str;
                }
            }
            if(isPalindromic(str) &&str.length()>palindrome.length()){
                palindrome=str;
                 cout<<str<<endl;
            }
        }
        return palindrome;
    }

int main(){
    
    cout<<longestPalindrome("cbbd")<<endl;

    return 0;
}

