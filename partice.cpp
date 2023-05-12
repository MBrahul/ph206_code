#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     int a,b;
     cin>>a>>b;
     vector<vector<int> > vect;
     for(int i=0;i<a;i++){
         int n;
         cin>>n;
         vector<int> v;
         for(int t =0;t<n;t++){
             int b;
             cin>>b;
             v.push_back(b);
         }
         vect.push_back(v);
     }
     vector<vector<int> > query;
     for(int i=0;i<b;i++){
         vector<int> v1;
         for(int t =0;t<2;t++){
             int b;
             cin>>b;
             v1.push_back(b);
         }
         query.push_back(v1);
     }
     cout<<vect[query[0][0]][query[0][1]]<<endl;
     cout<<vect[query[1][0]][query[1][1]]<<endl;
     
     
     
    return 0;
}