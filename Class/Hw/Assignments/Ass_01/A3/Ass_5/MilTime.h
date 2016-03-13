/* 
 * File:   MilTime.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 9:56 AM
 */

#ifndef MILTIME_H
#define	MILTIME_H

#include "Time.h"

class MilTime : public Time
{
    private:
        int milHours;
        int milSeconds;
    public:
        //Default constructor
        MilTime() : Time()
        {
            milHours = 0;
            milSeconds = 0;
        }
        
        //Constructor with user input
        MilTime(int h, int s)
        {
            setTime(h, s);
        }
        
        //Exceptions
        class BadHour{};
        class BadSeconds{};
        
        //Accessors
        int getMilHours() const { return milHours; }
        int getMilSeconds() const { return milSeconds; }
        
        //Function to calculate military time
        void setTime(int, int);
};

#endif	/* MILTIME_H */

