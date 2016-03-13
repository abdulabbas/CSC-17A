/* 
 * File:   date.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 8:08 AM
 */

#ifndef DATE_H
#define	DATE_H

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        Date(int, int, int);  //Constructor
        
        void setMonth(int);
        void setDay(int);
        void setYear(int);
        
        int getMonth() const 
            {return month;}  //Access Month Value
        int getDay() const 
            {return day;}    //Access Day Value
        int getYear() const 
            {return year;}  //Access Year Value
        
        void prntD1();  //Prints Date in MM/DD/YYYY Format
        void prntD2();  //Prints Date in Month DD, YYYY Format
        void prntD3();  //Prints Date in DD Month YYYY Format
        

};
#endif	/* DATE_H */


