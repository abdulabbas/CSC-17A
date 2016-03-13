/* 
 * File:   NumDays.h 
 * Author: Abdul-Hakim 
 * Created on November 17, 2015, 10:19 PM 
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H

class NumDays {
    private:
        float days;    //Days of work in a 8 hour shift
        float hours;   //Hours worked
    public:
        NumDays(float);                         //Constructor
        float getDay() const {return days;}     //Accessor for days
        float getHour() const {return hours;}   //Accessor for hours
        NumDays operator+(const NumDays&);      // + operator
        NumDays operator-(const NumDays&);      // - operator
        NumDays operator++(int);                //postfix ++ operator
        NumDays operator++();                   //prefix ++ operator
        NumDays operator--(int);                //postfix -- operator
        NumDays operator--();                   //prefix -- operator
};

#endif	/* NUMDAYS_H */