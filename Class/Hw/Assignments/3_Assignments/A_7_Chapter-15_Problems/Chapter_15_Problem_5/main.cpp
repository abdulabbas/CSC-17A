/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Chapter_15_Prob_5 
 * Created on September 28, 2015, 7:57 PM
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
    
    int hr,sec, hr2, sec2;
    
    do{
    cout<<endl;
    cout<<"Enter times in Military format (ex. 2359 for 11:59pm) "<<endl;
    cout<<"Start Time: ";
    cin>>hr;
    cout<<"End Time: ";
    cin>>hr2;
           
    }while(hr<0000 || hr>2400 && hr2<0000 || hr2>2400);
    
    sec=0;
    sec2=0;
    MilTime time(hr, sec);
    MilTime time2(hr2, sec2);
    time.setTime(hr, sec);
    time2.setTime(hr2, sec2);
    
    //cout<<"You entered the following time. "<<endl<<endl;
    //cout<<"Military Format: "<<setw(4)<<setfill('0')<<time.getHour()<<" Hundred Hours"<<endl;
    
    cout<<endl;
    
    //Start Time
    
    if(time.getStandHr()==0){
            
        cout<<"Start Time: "<<"12"<<":"<<setw(2)<<setfill('0')<<time.getMin()<<" AM";
            cout<<endl;
    }else if(time.getHour()<13){
            cout<<"Start Time: "<<time.getHour()<<":"<<setw(2)<<setfill('0')<<time.getMin();
                    if(hr>=1200){
                        cout<<" PM";
                    }else{
                        cout<<" AM";
                    }
            cout<<endl;
    }else{
        cout<<"Start Time: "<<time.getStandHr()<<":"<<setw(2)<<setfill('0')<<time.getMin();
            if(hr>=1200){
                cout<<" PM";
            }else{
                cout<<" AM";
            }
    cout<<endl;
    }
    
    
    //End Time
     if(time2.getStandHr()==0){
            
        cout<<"End Time: "<<"12"<<":"<<setw(2)<<setfill('0')<<time2.getMin()<<" AM";
            cout<<endl;
    }else if(time2.getHour()<13){
            cout<<"End Time: "<<time2.getHour()<<":"<<setw(2)<<setfill('0')<<time2.getMin();
                    if(hr>=1200){
                        cout<<" PM";
                    }else{
                        cout<<" AM";
                    }
            cout<<endl;
    }else{
        cout<<"End Time: "<<time2.getStandHr()<<":"<<setw(2)<<setfill('0')<<time2.getMin();
            if(hr>=1200){
                cout<<" PM";
            }else{
                cout<<" AM";
            }
    cout<<endl;
    }
    
    cout<<endl;
    int totHr, totMin;
    totHr=(time2.getHour()-time.getHour())/100;
    totMin=(time2.getMin()+time.getMin());
    
    if(totMin>=60){
        totHr++;
        totMin-=60;
        cout<<"Elapse Time : "<<totHr<<" Hour(s) and "<<totMin<<" Minutes"<<endl;
    }else 
        cout<<"Elapse Time : "<<totHr<<" Hour(s) and "<<totMin<<" Minutes"<<endl;
    
    
    cout<<endl;
    
    //Exit Stage Right
    return 0;
}