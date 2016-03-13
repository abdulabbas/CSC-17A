/* 
 * File:   DayOfYear.cpp
 * Author: Abdul-Hakim
 * Created on September 28, 2015, 9:11 AM
 */

#include "DayOfYear.h"

using namespace std;

//Declaring static variables
int DayOfYear::dayMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string DayOfYear::months[12] = {"Junuary", "February", "March", "April", "May", 
                                "June", "July", "August", "September", 
                                "October", "November", "December"};

//Constructor
DayOfYear::DayOfYear(int d)
{
    day = d;
}

//Accessor to print results
void DayOfYear::print() const
{
    int i = 0;           //Setting counter to 0
    int tempDay = day;   //Declaring local day variable
    
    //Loop to calculate the day
    while ( tempDay > dayMonth[i] ) 
    {
        tempDay-= dayMonth[i];
        i++;
    }
    
    //Printing results
    cout << "\nDay " << day << " is: " << months[i] << " " << tempDay << endl;
}

