/* 
 * File:   DayOfYear.cpp 
 * Author: Abdul-Hakim 
 * Created on November 17, 2015, 10:20 PM 
 */

#include "DayOfYear.h"

using namespace std;

//Declaring static variables
int DayOfYear::dayMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string DayOfYear::months[12] = {"January", "February", "March", "April", "May", 
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

