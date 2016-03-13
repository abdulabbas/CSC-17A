/* 
 * File:   Employee.cpp 
 * Author: Abdul-Hakim 
 * Created on December 12, 2015, 11:23 AM 
 */

#include <cstdlib>
#include <iostream>

#include "Employee.h"

using namespace std;

Employee::Employee( char n[], char t[], float r)
{
    for(int i = 0; i < 20; i++)
    {
        MyName[i] = n[i];
        JobTitle[i] = t[i];
    }
    setHourlyRate(r);
    HoursWorked = 0;
    GrossPay = 0.0;
    NetPay = 0.0; 
}

double Employee::Tax(float gp)
{
    if (gp  <= 500)
    {
        return gp*0.1;
    }
    else if(gp > 500 &&  gp <= 1000)
    {
        return gp*0.2;
    }
    else if(gp > 1000)
    {
        return gp*0.3;
    }
}

float Employee::CalculatePay(float x,int y)
{
    return getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
}

float Employee::getGrossPay(float r,int h)
{
    if(h <= 40)
    {
        GrossPay = r*h;
        return GrossPay;
    }
    else if(h > 40 && h <= 50)
    {
        GrossPay = (r * h) + (((h - 40) * r)/2);
        return GrossPay;
    }
    else if(h > 50)
    {
        GrossPay = (r * h) + (((r/2) + r) * (h - 50));
        return GrossPay;
    }
}

float Employee::getNetPay(float gp)
{
    NetPay = gp-Tax(gp);
    return NetPay;
}

void Employee::toString()
{
    cout << "\nName = " << MyName << endl;
    cout << "Job Title = " << JobTitle << endl;
    cout << "Hourly Rate = " << HourlyRate << endl;
    cout << "Hours Worked = " << HoursWorked << endl;
    cout << "Gross Pay = " << GrossPay << endl;
    cout << "Net Pay = " << NetPay << endl;
}

int  Employee::setHoursWorked(int hw)
{
    if(hw > 0 && hw < 84)
    {
        HoursWorked = hw;
        return HoursWorked;
    }
    else
    {
        cout << "Unacceptable Hours Worked" << endl;
        HoursWorked = 0;
        return 0;
    }
}

float Employee::setHourlyRate(float hr) 
{
    if(hr > 0 && hr < 200)
    {
        HourlyRate = hr;
        return hr;
    }
    else
    {
        cout << "Unacceptable Hourly Rate" << endl;
        HourlyRate = 0.0;
        return 0.0;
    }
}


