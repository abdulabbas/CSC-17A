/* 
 * File:   MilTime.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 10:37 AM
 */


#include "MilTime.h"


void MilTime::setTime(int h, int s)
{
    //Calling exception class if invalid input
    if (h >= 0 && h <= 2359)
        milHours = h;     //Military hours
    else
        throw BadHour();
    
    if (s >= 0 && s <= 59)
        milSeconds = s;   //Military seconds
    else
        throw BadSeconds();
    
    //Initializing variables
    int tempHours;         //Temporary hours
    int tempMinutes;       //Temporary Minutes
    string tempMeridiem;   //Meridiem AM or PM
    
    if(h > 1259)
    {
        tempMeridiem = "PM";
        tempHours =  (h / 100) - 12;
        tempMinutes = h % 100;
       
        //Calling Time mutators
        setMeridiem(tempMeridiem);
        setSeconds(milSeconds);
        setHour(tempHours);
        setMinutes(tempMinutes);
    }
    else if(h < 1300)
    {
        tempMeridiem = "AM";
        tempHours =  (h / 100);
        tempMinutes = h % 100;
       
        //Calling Time mutators
        setMeridiem(tempMeridiem);
        setSeconds(milSeconds);
        setHour(tempHours);
        setMinutes(tempMinutes);
    }
    
}
