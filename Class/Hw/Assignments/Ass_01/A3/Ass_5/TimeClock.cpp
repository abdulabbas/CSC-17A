/* 
 * File:   TimeClock.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 10:48 AM
 */

#include "TimeClock.h"


//Function to calculate the time elapsed
void TimeClock::calcTimeElapsed(int start, int end)
{
    int tempHours;     //Temporary variable to hold the difference in time
    int tempMinutes;   //Temporary stores the minutes
    int tempTime;      //Time to be passed to the setTime function
    int stHours;       //Starting hours
    int enHours;       //Ending hours
    int stMinutes;     //Starting Minutes
    int enMinutes;     //Ending minutes
    
    //Separating hours from minutes
    stHours = start/100;
    enHours = end/100;
    stMinutes = start % 100;
    enMinutes = end % 100;
    
    //Calculating difference between hours
    if(stHours <= enHours)
        tempHours = enHours - stHours;
    else if(stHours > enHours)
        tempHours = (24 - stHours) + enHours;
    
    //Calculating difference between minutes
    if(stMinutes <= enMinutes)
        tempMinutes = enMinutes - stMinutes;
    else if(stMinutes > enMinutes)
    {
        tempMinutes = (60 - stMinutes) + enMinutes;
        tempHours -= 1;
    }
    
   
    //Putting difference in minutes and hours together
    tempTime = (tempHours * 100) + tempMinutes;
    
    //Function from the MilTime class
    
    setTime(tempTime, 0);
                
}
