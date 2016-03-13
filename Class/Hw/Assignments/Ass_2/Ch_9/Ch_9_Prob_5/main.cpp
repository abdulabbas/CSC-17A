/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Ch_9_Problem_5
 * Created on September 24, 2015, 10:03 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
int doSomething(int *, int *);
int result(int *, int *);

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    int a, b;
    
    cout<<"Enter a value for x: ";
    cin>>a;
    cout<<endl;
    cout<<"Enter a value for y: ";
    cin>>b;
    cout<<endl;
    
    doSomething(&a, &b);
    result(&a, &b);
    
    
    //Exit Stage Right
    return 0;
}

int doSomething(int *x, int *y){
    
    int temp=*x;
    *x=*y*10;
    *y=temp*10;
    
    return *x+*y;
}

int result(int *x, int *y){
    cout<<*x+*y;
    cout<<endl;
}