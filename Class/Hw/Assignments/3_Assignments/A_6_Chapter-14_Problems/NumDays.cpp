/* 
 * File:   NumDays.cpp 
 * Author: Abdul-Hakim 
 * Created on November 17, 2015, 10:28 PM 
 */

#include "NumDays.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Constructor
NumDays::NumDays(float h)
{
    hours = h;
    days = hours / 8.0;
}

// + operator function
NumDays NumDays::operator+(const NumDays &right)
{
    NumDays temp(0);
    temp.hours = hours + right.hours;
    temp.days = days + right.days;
    return temp;
}
// - operator function
NumDays NumDays::operator-(const NumDays &right)
{
    NumDays temp(0);
    temp.hours = hours - right.hours;
    temp.days = days - right.days;
    return temp;
}

//Overload prefix ++ operator
NumDays NumDays::operator++()
{
    ++days;
    return *this;
}

//Overload postfix ++ operator
NumDays NumDays::operator ++ (int)
{
    NumDays temp(hours);
    days++;
    return temp;
}

//Overload prefix -- operator
NumDays NumDays::operator -- ()
{
    --days;
    return *this;
}

//Overload postfix -- operator
NumDays NumDays::operator -- (int)
{
    NumDays temp(hours);
    days--;
    return temp;
}
