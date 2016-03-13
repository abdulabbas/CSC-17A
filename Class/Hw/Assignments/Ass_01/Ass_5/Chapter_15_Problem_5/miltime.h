/* 
 * File:   miltime.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:58 PM
 */


#ifndef MILTIME_H
#define	MILTIME_H
#include "time.h"

class MilTime : public Time{
    private:
        int milHour;
        int milSeconds;
    public:
        MilTime(){
            milHour=0;
            milSeconds=0;
        }
              
        MilTime(int mH, int mS){
            milHour=mH;
            milSeconds=mS;
        }
        
        void setTime(int mH, int mS);
        
        int getHour()
            {return milHour;}
        int getStandHr()
            {return hour%12;}
        
};


#endif	/* MILTIME_H */


