/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Chapter_15_Prob_4
 * Created on September 28, 2015, 7:47 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
//User Libraries
#include "miltime.h"
#include "time.h"
using namespace std;

//Global Constants
//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    int hr,sec;
    
    do{
    cout<<endl;
    cout<<"Enter time in Military format (ex. 2359 for 11:59pm): ";
    cin>>hr;
    }while(hr<0000 || hr>2400);
    
    sec=0;
    MilTime time(hr, sec);
    time.setTime(hr, sec);
    
    cout<<"You entered the following time. "<<endl<<endl;
    cout<<"Military Format: "<<setw(4)<<setfill('0')<<time.getHour()<<" Hundred Hours"<<endl;
    
    if(time.getStandHr()==0){
            cout<<"Standard Format: "<<"12"<<":"<<time.getMin()<<" AM";
            cout<<endl;
    }else if(time.getHour()<13){
            cout<<"Standard Format: "<<time.getHour()<<":"<<time.getMin();
                    if(hr>1159){
                        cout<<" PM";
                    }else{
                        cout<<" AM";
                    }
            cout<<endl;
    }else{
        cout<<"Standard Format: "<<time.getStandHr()<<":"<<time.getMin();
            if(hr>1159){
                cout<<" PM";
            }else{
                cout<<" AM";
            }
    cout<<endl;
    }
    //Exit Stage Right
    return 0;
}

