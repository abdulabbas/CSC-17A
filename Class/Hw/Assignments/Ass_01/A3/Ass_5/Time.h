/* 
 * File:   Time.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 10:02 AM
 */

#ifndef TIME_H
#define	TIME_H

#include <string>

using namespace std;

class Time 
{
    private:
        int hour;          //Holds the hour
        int minutes;       //Holds the minutes
        int seconds;       //Holds the seconds
        string meridiem;   //Holds the meridiem AM or PM
    public:
        //Default Constructor
        Time()
        { 
            hour = 0; 
            minutes = 0; 
            seconds = 0;
        }

        //Constructor with user input
        Time(int h, int m, int s)
        { 
            hour = h; 
            minutes = m; 
            seconds = s; 
        }

        //Mutators
        void setHour(int h) { hour = h;}
        void setMinutes(int m) { minutes = m;}
        void setSeconds(int s) { seconds = s;}
        void setMeridiem (string mer) { meridiem = mer;}
        
        //Accessors
        int getHour() const { return hour;}
        int getMinutes() const { return minutes; }
        int getSeconds() const { return seconds; }
        string getMeridiem() const { return meridiem;}
};

#endif	/* TIME_H */
