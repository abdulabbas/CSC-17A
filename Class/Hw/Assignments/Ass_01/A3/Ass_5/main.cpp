/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Assignment_5 
 * Created on September 28, 2015, 9:43 AM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

//Classes 
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
#include "MilTime.h"
#include "TimeClock.h"
#include "Date.h"
#include "MinMax.h"
#include "IntArray.h"
#include "SearchableVector.h"

using namespace std;

//Problems Prototypes
void Menu();
int getN();
void def(int);
void problem1();   //Ch 15 problem 1
void problem2();   //Ch 15 problem 2
void problem3();   //Ch 15 problem 3
void problem4();   //Ch 15 problem 4
void problem5();   //Ch 15 problem 5
void problem6();   //Ch 16 problem 1
void problem7();   //Ch 16 problem 2
void problem8();   //Ch 16 problem 3
void problem9();   //Ch 16 problem 6
void problem10();  //Ch 16 problem 9

//Begin Execution Here!!!
int main(int argv,char *argc[])
{
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;   //Ch 15 problem 1
        case 2:    problem2();break;   //Ch 15 problem 2
        case 3:    problem3();break;   //Ch 15 problem 3
        case 4:    problem4();break;   //Ch 15 problem 4
        case 5:    problem5();break;   //Ch 15 problem 5
        case 6:    problem6();break;   //Ch 16 problem 1
        case 7:    problem7();break;   //Ch 16 problem 2
        case 8:    problem8();break;   //Ch 16 problem 3
        case 9:    problem9();break;   //Ch 16 problem 6
        case 10:    problem10();break; //Ch 16 problem 9
        default:   def(inN);}
    }while(inN>=1&&inN<=10);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for assignment 5"<<endl;
    cout<<"Type 1 for problem 15.1"<<endl;
    cout<<"Type 2 for problem 15.2"<<endl;
    cout<<"Type 3 for problem 15.3"<<endl;
    cout<<"Type 4 for problem 15.4"<<endl;
    cout<<"Type 5 for problem 15.5"<<endl;
    cout<<"Type 6 for problem 16.1"<<endl;
    cout<<"Type 7 for problem 16.2"<<endl;
    cout<<"Type 8 for problem 16.3"<<endl;
    cout<<"Type 9 for problem 16.6"<<endl;
    cout<<"Type 10 for problem 16.9"<<endl;
    cout<<"Type anything else to exit \n"<<endl;}

int getN(){
        int inN;
        cin>>inN;
        return inN;}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Ch 15 problem 1
void problem1()
{
    string name = " ";    //Holds employee name
    int id = 0;           //Holds employee ID number
    string hire = " ";    //Holds employee hire date
    int shift  = 0;       //Holds employee shifts 1 = day, 2 = night
    float payRate  = 0;   //Holds employee hourly pay rate

    //User input for the Employee class
    cout << "Enter the employee's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the employee's ID number: ";
    cin >> id;
    cout << "Enter the employee's hire date (mm/dd/yyyy format): ";
    cin.ignore();
    getline(cin, hire);

    //User input for the ProductionWorker class
    cout << "\nEnter " << name << "'s shift (1 = day, 2 = night): ";
    cin >> shift;
    cout << "Enter " << name << "'s hourly pay rate: ";
    cin >> payRate;

    //Set inputs
    ProductionWorker worker(name, id, hire, shift, payRate);

    //Output data
    cout << "\nEmployee's information: " << endl;
    cout << "Name: "  << worker.getName()  << endl;
    cout << "Number : "   << worker.getId()   << endl;
    cout << "Hire date: " << worker.getHire() << endl;
    cout << "Shift: " << worker.getShift() << endl;
    cout << "Hourly pay rate: " << worker.getPayRate() << endl;
    cout << endl;
}

//Ch 15 problem 2
void problem2()
{
    string name = " ";    //Holds employee name
    int id = 0;           //Holds employee ID number
    string hire = " ";    //Holds employee hire date
    float salary  = 0;    //Holds employee annual salary
    float bonus  = 0;     //Holds employee end of year bonus

    //User input for the Employee class
    cout << "Enter the employee's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the employee's ID number: ";
    cin >> id;
    cout << "Enter the employee's hire date (mm/dd/yyyy format): ";
    cin.ignore();
    getline(cin, hire);

    //User input for the ProductionWorker class
    cout << "\nEnter " << name << "'s annual salary: ";
    cin >> salary;
    cout << "Enter " << name << "'s end of year bonus: ";
    cin >> bonus;

    //Set inputs
    ShiftSupervisor worker2(name, id, hire, salary, bonus);

    //Output data
    cout << "\nEmployee's information: " << endl;
    cout << "Name: "  << worker2.getName()  << endl;
    cout << "Number : "   << worker2.getId()   << endl;
    cout << "Hire date: " << worker2.getHire() << endl;
    cout << "Annual salary: " << worker2.getSalary() << endl;
    cout << "End of year bonus: " << worker2.getBonus() << endl;
    cout << endl; 
}

//Ch 15 problem 3
void problem3()
{
    string name = " ";          //Holds employee name
    int id = 0;                 //Holds employee ID number
    string hire = " ";          //Holds employee hire date
    int shift  = 0;             //Holds employee shifts 1 = day, 2 = night
    float payRate  = 0.0;       //Holds employee hourly pay rate
    float amountBonus = 0.0;    //Bonus amount if completed hours
    float hoursReq = 0.0;       //Required hours to get the bonus
    float hoursAttend = 0.0;    //Hours attended by the employee

    //User input for the Employee class
    cout << "Enter the employee's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the employee's ID number: ";
    cin >> id;
    cout << "Enter the employee's hire date (mm/dd/yyyy format): ";
    cin.ignore();
    getline(cin, hire);

    //User input for the ProductionWorker class
    cout << "\nEnter " << name << "'s shift (1 = day, 2 = night): ";
    cin >> shift;
    cout << "Enter " << name << "'s hourly pay rate: ";
    cin >> payRate;
    
    //User input for the TeamLeader class
    cout << "\nEnter the bonus amount: ";
    cin >> amountBonus;
    cout << "Enter the required hours to earn the bonus: ";
    cin >> hoursReq;
    cout << "Enter " << name << "'s completed hours: ";
    cin >> hoursAttend;

    //Set inputs
    TeamLeader worker3(name, id, hire, shift, payRate, amountBonus, hoursReq, hoursAttend);
    
    //Calling function from the TeamLeader class to calculate the total pay
    worker3.calcTotal();

    //Output data
    cout << "\nEmployee's information: " << endl;
    cout << "Name: "  << worker3.getName()  << endl;
    cout << "Number : "   << worker3.getId()   << endl;
    cout << "Hire date: " << worker3.getHire() << endl;
    cout << "Shift: " << worker3.getShift() << endl;
    cout << "Hourly pay rate: " << worker3.getPayRate() << endl;
    cout << "Hours worked: " << worker3.getAttendHours() << endl;
    cout << "Total payment including bonus: " << worker3.getTotal() << endl;
    cout << endl;
}

//Ch 15 problem 4
void problem4()
{
    int mHours = 0;     //Military time
    int mSeconds = 0;   //Military seconds
    
    //Requesting input with validation
    cout << "\nEnter the military time you want to convert to standard time: ";
    cin >> mHours;
    while(mHours < 0 || mHours > 2359 || (mHours%100) < 0 ||(mHours%100) > 59)
    {
        cout << "\nERROR! Hours must be 0 - 2359 with minutes 0 - 59" << endl;
        cout << "Enter the military time you want to convert to standard time: ";
        cin >> mHours;
    }
    cout << "Enter the seconds: ";
    cin >> mSeconds;
    while(mSeconds < 0 || mSeconds > 59)
    {
        cout << "\nERROR! Seconds must be 0 - 59" << endl;
        cout << "Enter the seconds: ";
        cin >> mSeconds;
    }
    
    //Declaring class object
    MilTime time(mHours, mSeconds);
    
    //Printing output
    cout << "\nMilitary time: " << time.getMilHours() << ":" 
         << time.getMilSeconds() << endl;
    cout << "Standard time: " << time.getHour() << ":" << time.getMinutes()
         << ":" << time.getSeconds() <<" "<< time.getMeridiem() << endl << endl;
}

//Ch 15 problem 5
void problem5()
{
    int time1 = 0;   //Starting military time
    int time2 = 0;   //Ending military time
    
    //Requesting input with validation
    cout << "\nEnter the starting time in military format: ";
    cin >> time1;
    while(time1 < 0 || time1 > 2359 || (time1%100) < 0 ||(time1%100) > 59)
    {
        cout << "\nERROR! time must be 0 - 2359 with minutes 0 - 59" << endl;
        cout << "Enter the starting time in military format: ";
        cin >> time1;
    }
    cout << "Enter the ending time in military format: ";
    cin >> time2;
    while(time2 < 0 || time2 > 2359 || (time2%100) < 0 ||(time2%100) > 59)
    {
        cout << "\nERROR! time must be 0 - 2359 with minutes 0 - 59" << endl;
        cout << "Enter the ending time in military format: ";
        cin >> time2;
    }
    
    //Declaring TimeClock object
    TimeClock timeElapsed(time1, time2);
    
    //Printing output
    cout << "\nThe time elapsed between " << time1 << " and " << time2 << " is: "
         << timeElapsed.getHour() << ":" << timeElapsed.getMinutes() 
         <<  " hours." << endl << endl;
}

//Ch 16 problem 1
void problem6()
{
    Date formats;   //Define instance of Date class
    int month;      //Holds month
    int day;        //Holds day
    int year;       //Holds year
    
    //Get user input
    cout << "\nPlease enter the Month: ";
    cin >> month;
    cout << "Please enter the Day: ";
    cin >> day;
    cout << "Please enter the Year: ";
    cin >> year;
    
    try
    {
        formats.setMonth(month);
        formats.setDay(day);
        formats.setYear(year);
        
        //Printing the dates in the corresponding formats
        cout << "\nHere is the date in three different formats:" << endl;
        formats.allNumbers();
        formats.monthFirst();
        formats.dayFirst();
    }
    catch(Date::InvalidMonth)
    {
        cout << "\nInvalid Month!\nMonth must be from 1 - 12" << endl;
    }
    catch(Date::InvalidDay)
    {
        cout << "\nInvalid Day!\nDay must be from 1 - 31" << endl;
    }
    cout <<  endl;
}

//Ch 16 problem 2
void problem7()
{
    int mHours = 0;     //Military time
    int mSeconds = 0;   //Military seconds
    
    //Requesting input with validation
    cout << "\nEnter the military time you want to convert to standard time: ";
    cin >> mHours;
     cout << "Enter the seconds: ";
    cin >> mSeconds;
    
    try
    {
        //Declaring class object
        MilTime time(mHours, mSeconds);
        
        //Printing output
        cout << "\nMilitary time: " << time.getMilHours() << ":" 
        << time.getMilSeconds() << endl;
        cout << "Standard time: " << time.getHour() << ":" << time.getMinutes()
        << ":" << time.getSeconds() <<" "<< time.getMeridiem() << endl;
    }
    catch(MilTime::BadHour)
    {
        cout << "\nERROR! Hours must be 0 - 2359" << endl;
    }
    catch(MilTime::BadSeconds)
    {
        cout << "\nERROR! Seconds must be 0 - 59" << endl;
    }
   
    cout << endl;
}

//Ch 16 problem 3
void problem8()
{
    float number1 = 0.0;   //Holds first number
    float number2 = 0.0;   //Holds second number
    
    cout << "\nEnter 2 numbers" << endl;
    cout << "Number 1: ";
    cin >> number1;
    cout <<"Number 2: ";
    cin >> number2;
    
    MinMax<float> arguments(number1, number2);
    
    cout << "\nThe smallest number is: ";
    cout << arguments.minimum() << endl;
    cout << "The largest number is: ";
    cout << arguments.maximum() << endl;
    cout << endl;
}

//Ch 16 problem 6
void problem9()
{
    int size = 0;    //Size of the array
    int index = 0;   //Number to search in the array
    
    cout << "\nEnter the size of an array: ";
    cin >> size;
    
    IntArray table(size);
    
    // Store values in the array. 
    cout << "\nFilling the array with numbers..." << endl;
    for (int x = 0; x < size; x++) 
    table[x] = x+7%3; 
    
    cout <<"\nEnter the position in the array to see its number(exceed array size to activate exception) ";
    cin >> index;
    
    try
    {
        cout <<"\nPosition " << index << " holds number: " << table[index] <<endl;
    }
    catch(IntArray::subscriptError)
    {
        cout << "\nERROR: Subscript out of range.\n";
    }
    
    cout << endl;
}

//Ch 16 problem 9
void problem10()
{
    const int SIZE = 10;   //Size of the array
    int count;             //Counter for the loops
    int result;            //Result if item found
    int intNum;            //Int to search in the array
    float floatNum;        //Float to search in the array

    //Create two SearchableVector objects
    SearchableVector<int> intTable(SIZE);
    SearchableVector<float> floatTable(SIZE);

    //Store values in the objects
    for (count = 0; count < SIZE; count++)
    {
        intTable[count] = (count * 2);
        floatTable[count] = (count * 2.14);
    }

    //Display the values in the objects
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl << endl;
    cout << "These values are in floatTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << floatTable[count] << " ";
    cout << endl;

    cout << "\nEnter the int number you would like to search in the int table: ";
    cin >> intNum;
    
    //Search for the value in intTable
    cout << "\nSearching for " << intNum << " in intTable.\n";
    result = intTable.findItem(intNum);
    if (result == -1)
        cout << intNum << " was not found in intTable.\n";
    else
        cout << intNum << " was found at subscript " << result+1 << endl;

    cout << "\nEnter the float you would like to search in the floatNum table: ";
    cin >> floatNum;
    
    //Search for the value 12.84 in floatTable
    cout << "\nSearching for " << floatNum << " in floatTable.\n";
    result = floatTable.findItem(floatNum);
    if (result == -1)
        cout << floatNum << " was not found in floatTable.\n";
    else
        cout << floatNum << " was found at subscript " << result+1 << endl;

    cout << endl;
}

