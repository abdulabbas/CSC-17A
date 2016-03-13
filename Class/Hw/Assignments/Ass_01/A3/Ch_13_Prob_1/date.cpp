/* 
 * File:   date.cpp
 * Author: Abdul-Hakim
 * Purpose: Ch_13_Prob_1
 * Created on September 28, 2015, 8:15 AM
 */
//System Libraries
#include "date.h"
#include <iostream>
#include <cstdlib>
//User Libraries
using namespace std;
//Global Constants
//Function Prototypes
//Execution Begins Here!
//Constructor accepts arguments for month, date, and year
Date::Date(int mm, int dd, int yy){
    month=mm;
    day=dd;
    year=yy;  
}

//Sets the value of the member variable month
void Date::setMonth(int mm){
    if (mm<=12 && mm>0){
        month=mm;
    }else
        cout<<"Invalid Month"<<endl;
        exit(EXIT_FAILURE);
}

//Sets the value of the member variable day
void Date::setDay(int dd){
    if(dd<=31 && dd>0){
        day=dd;
    }else
        cout<<"Invalid Day"<<endl;
        exit(EXIT_FAILURE);
}

//Sets the value of the member variable year
void Date::setYear(int yy){
    if (yy>=0){
        year=yy;
    }else
        cout<<"Invalid Year"<<endl;
        exit(EXIT_FAILURE);
    
}

void Date::prntD1(){
    cout<<month<<"/"<<day<<"/"<<year;
}

void Date::prntD2(){
    if(month==1){
        cout<<"January "<<day<<", "<<year;
    }else if(month==2){
        cout<<"February "<<day<<", "<<year;
    }else if (month==3){
        cout<<"March "<<day<<", "<<year;
    }else if (month==4){
        cout<<"April "<<day<<", "<<year;
    }else if (month==5){
        cout<<"May "<<day<<", "<<year;
    }else if (month==6){
        cout<<"June "<<day<<", "<<year;
    }else if (month==7){
        cout<<"July "<<day<<", "<<year;
    }else if (month==8){
        cout<<"August "<<day<<", "<<year;
    }else if (month==9){
        cout<<"September "<<day<<", "<<year;
    }else if (month==10){
        cout<<"October "<<day<<", "<<year;
    }else if (month==11){
        cout<<"November "<<day<<", "<<year;
    }else if (month==12){
        cout<<"December "<<day<<", "<<year;
    } 
}

void Date::prntD3(){
    if(month==1){
        cout<<day<<" January "<<year;
    }else if(month==2){
        cout<<day<<" February "<<year;
    }else if (month==3){
        cout<<day<<" March "<<year;
    }else if (month==4){
        cout<<day<<" April "<<year;
    }else if (month==5){
        cout<<day<<" May "<<year;
    }else if (month==6){
        cout<<day<<" June "<<year;
    }else if (month==7){
        cout<<day<<" July "<<year;
    }else if (month==8){
        cout<<day<<" August "<<year;
    }else if (month==9){
        cout<<day<<" September "<<year;
    }else if (month==10){
        cout<<day<<" October "<<year;
    }else if (month==11){
        cout<<day<<" November "<<year;
    }else if (month==12){
        cout<<day<<" December "<<year;
    } 
}
