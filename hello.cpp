// header files
#include <iostream>
#include <iomanip>
#include<vector>
using namespace std;


// ****************struct and union *************
// struct = user define datatype
// struct student
// {
//  string name;
//  int marks;
//  int age; 
// };

// union - this is also usr define datatype but it must have only one parameter value among all;
// union option
// {
//  int a;
//  int b;
//  int c; 
// };



// local and global variable can have same name but first preference goes to local variable
// int a = 10;
int main()
{
    // int a = 20;
    // <<  insertion operator
    // >> extraction operator
    //  cout<<"hello world\n";
    //  cout<<a;
    // cout<<::a; this will print global a, :: scope resolution operator

    // **************** taking input from user ******************
    // int num1, num2;
    // cout << "Enter the value of Num1:";
    // cin >> num1;
    // cout << "Enter the value of Num2:";
    // cin >> num2;
    // cout << "sum:" << num1 + num2 << '\n';

    // **************** reference variable ******************
    //  float x=455;
    //  float &y =x;
    //  cout<<x<<endl;
    //  cout<<y<<endl;

    // **************** typecasting of datatypes  *****************
    // change datatype of a variable
    // float i = 45.67f;
    // cout<<int(i)<<endl;
    // cout<<(int)(i)<<endl;
    // cout<<(int)i<<endl;
    // cout<<(double)(i)<<endl;


    // **************** Manipulator ******************
    // manipulator - used in to display data in a good formate
    // for example - endl , set(w) from iomanip
    // int x =12, y=77,z=2;
    // cout<<"the value of a:"<<setw(4)<<a<<endl;
    // setw() sets number of spaces in which variable a is going to print 


     // **************** Pointers ******************
     // datatype - which holds the other datatype's address
    //  int a = 3;
    //  int* b = &a;

    //  cout<<"Address of a is "<<b<<endl;
    //  cout<<"Address of a is "<<&a<<endl;
    //  // * -(value at ) difference operator 
    //  cout<<"value of a is "<<*b<<endl;

    //  // pointer to pointer

    //  int** c = &b;
    //  cout<<"address of pointer b "<<*c<<endl;


   //**************Pointers and arrays ******************
//    int marks[] = {12,34,332,5,64};
//    cout<<marks<<endl;// print address of first element
//    cout<<*(marks)<<endl;//print value at 0th index
//    cout<<&marks[1]<<endl; // address of marks[1] == address of p + 1*sizeof(int){4 bytes}
   

// **************** struct and union and enum *************
// struct student rahul;
// rahul.name="rahul";
// rahul.age=20;
// rahul.marks=10;

// union option opt1;
// opt1.b=2;
// opt1.a=1;
// cout<<opt1.b<<endl;

// enum Meal{breakfast,lunch,dinner};
// cout<<breakfast<<endl;//print 0; 
// Meal m1 = breakfast;
// cout<<m1<<endl;//print 0 

//**************** vector and pair*****************
//vector is like a dynamic array;
// vector <int> v;
// v.push_back(1);
// v.push_back(12);
// v.push_back(14);
// v.pop_back();

// for(int i =0;i<v.size();i++){
//     cout<<v[i]<<endl;
// }

// // pair is used for store two diff. or same variable 
// pair<int ,int> my_pair;
// my_pair.first=12;
// my_pair.second=34;

    return 0;
}