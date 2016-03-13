/* 
 * File:   Date.cpp
 * Author: Abdul-Hakim 
 * Created on November 17, 2015, 8:23 PM
 */
//Libraries
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
// Constructor to initialize values
Date::Date()
{
    month = 0;  //Declaring month to 0
    day = 0;    //Declaring day to 0
    year = 0;   //Declaring year to 0
}

// Gets the month, day and year
void Date::getInput()
{
    //Getting the input
    cout << "\nPlease enter the Month: ";
    cin >> month;
    while(month <= 0 || month > 12)
    {
        cout << "\nInvalid input!" << endl;
        cout << "Please enter the month: ";
        cin >> month;
    }
    
    cout << "Please enter the Day: ";
    cin >> day;
    while(day <= 0 || day > 31)
    {
        cout << "\nInvalid input!" << endl;
        cout << "Please enter the Day: ";
        cin >> day;
    }
    
    cout << "Please enter the Year: ";
    cin >> year;
    cout <<  endl;
}

// Date in "mm/dd/yyyy" format
void Date::allNumbers()
{
    cout << month << "/" << day << "/" << year << endl;
}

// Date in "month day, year" format
void Date::monthFirst()
{
    //Declaring string array holding all the months
    string letMonth[12] = {"January", "February", "March", "April", "May", 
                           "June", "July", "August", "September", "October",
                           "November", "December"}; 
    
    //Printing output in corresponding format
    cout << letMonth[month-1] << " " << day << ", "<< year << endl;
    
    
}
        
// Date in "day month year" format 
void Date::dayFirst()
{
    //Declaring string array holding all the months
    string letMonth[12] = {"January", "February", "March", "April", "May", 
                           "June", "July", "August", "September", "October",
                           "November", "December"}; 
    
    //Printing output in corresponding format
    cout << day << " " << letMonth[month-1] << " " << year << endl;
}