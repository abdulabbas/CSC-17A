/* 
 * File:   DayOfYear.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 8:45 AM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class DayOfYear {
    private:
        int day;                  //Number of days input by the user
        static string months[];   //String array that holds the months
        static int dayMonth[];    //int array that holds the number of days
    public:
        DayOfYear(int);       //Constructor to declare members
        void print() const;   //Accessor to print results
};

#endif	/* DAYOFYEAR_H */

