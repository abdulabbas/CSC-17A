/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Ch_13_Prob_1
 * Created on September 28, 2015, 7:58 AM
 */
//System Libraries
#include <cstdlib>
#include <cstdlib>
#include <iostream>
//User Libraries 
#include "date.h"
using namespace std;
//Global constants
//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    int month,  //Will hold month
        day,    //Will hold day
        year;   //Will hold year
    
    //Input Month, Date, and Year
    cout<<"Enter the month (MM): ";
    cin>>month;
    cout<<"Enter the day (DD): ";
    cin>>day;
    cout<<"Enter the year (YY): ";
    cin>>year;
    //Creates the Date Object
    Date date(month, day, year);
    //Prints the Date Object
    cout<<endl;
    date.prntD1();
    cout<<endl;
    date.prntD2();
    cout<<endl;
    date.prntD3();
    cout<<endl;
    
    //Exit Stage Right
    return 0;
}

