/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: To find the max and min values from a users input
 * Created on July 3, 2015, 6:29 PM
 */

#include <iostream>

using namespace std;

//User Libraries
//Global Constants 
//Function Prototypes
//Execution Begins Here!
int main(int argc, char** argv) {
//Declare variables
    int n1,n2;//Holds the 2 entered values by the user
//Prompt for the 2 numbers that have to be entered
cout<<"Enter the 1st number"<<endl;
cin>>n1;
cout<<"Enter the 2nd number"<<endl;
cin>>n2;
//To output the maximum value
if(n1>n2)
    cout<<n1<<" is the larger number between the two numbers"<<endl;
else
    cout<<n2<<" is the larger number between the two numbers"<<endl;
//To output the minimum value
if(n1<n2)
    cout<<n1<<" is the smaller number between the two numbers"<<endl;
else
    cout<<n2<<" is the smaller number between the two numbers"<<endl;
    return 0;
}

