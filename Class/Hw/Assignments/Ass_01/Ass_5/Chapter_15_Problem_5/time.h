/* 
 * File:   time.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:58 PM
 */

#ifndef TIME_H
#define	TIME_H

class Time{
    protected:
        int hour;
        int min;
        int sec;
    public:
        
        //Default Construction
        Time(){
            hour=0;
            min=0;
            sec=0;
        }
        
        //Constructor
        Time(int h, int m, int s){
            hour=h;
            min=m;
            sec=s;
        }
        
        int getHour() const
            {return hour;}
        
        int getMin() const
            {return min;}
        
        int getSec() const
            {return sec;}
};

#endif	/* TIME_H */

