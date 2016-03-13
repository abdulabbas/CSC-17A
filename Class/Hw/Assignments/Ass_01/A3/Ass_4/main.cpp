/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Ass_4
 * Created on September 28, 2015, 7:55 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
//User Libraries
//Classes
#include "Date.h"
#include "Employee.h"
#include "PersonalInfo.h"
#include "Widget.h"
#include "Payroll.h"
#include "DayOfYear.h"
#include "NumDays.h"
#include "FeetInches.h"
#include "LandTract.h"
using namespace std;
//Global Constants
//Function Prototypes
//Problems Prototypes
void Menu();
int getN();
void def(int);
void problem1();   //Ch 13 problem 1
void problem2();   //Ch 13 problem 2
void problem3();   //Ch 13 problem 4
void problem4();   //Ch 13 problem 7
void problem5();   //Ch 13 problem 12
void problem6();   //Ch 14 problem 2
void problem7();   //Ch 14 problem 4
void problem8();   //Ch 14 problem 9
void problem9();   //Ch 14 problem 11
void problem10();  //Ch 14 problem 12
//Execution Begins Here!
int main(int argv,char *argc[])
{
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;   //Ch 13 problem 1
        case 2:    problem2();break;   //Ch 13 problem 2
        case 3:    problem3();break;   //Ch 13 problem 4
        case 4:    problem4();break;   //Ch 13 problem 7
        case 5:    problem5();break;   //Ch 13 problem 12
        case 6:    problem6();break;   //Ch 14 problem 2
        case 7:    problem7();break;   //Ch 14 problem 4
        case 8:    problem8();break;   //Ch 14 problem 9
        case 9:    problem9();break;   //Ch 14 problem 11
        case 10:    problem10();break; //Ch 14 problem 12
        default:   def(inN);}
    }while(inN>=1&&inN<=10);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for assignment 4"<<endl;
    cout<<"Type 1 for problem 13.1"<<endl;
    cout<<"Type 2 for problem 13.2"<<endl;
    cout<<"Type 3 for problem 13.4"<<endl;
    cout<<"Type 4 for problem 13.7"<<endl;
    cout<<"Type 5 for problem 13.12"<<endl;
    cout<<"Type 6 for problem 14.2"<<endl;
    cout<<"Type 7 for problem 14.4"<<endl;
    cout<<"Type 8 for problem 14.9"<<endl;
    cout<<"Type 9 for problem 14.11"<<endl;
    cout<<"Type 10 for problem 14.12"<<endl;
    cout<<"Type anything else to exit \n"<<endl;}

int getN(){
        int inN;
        cin>>inN;
        return inN;}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Ch 13 problem 1
void problem1()
{
    Date formats;   //Define instance of Date class
    
    //Get user input
    formats.getInput();
    
    //Printing the dates in the corresponding formats
    cout << "\nHere is the date in three different formats:" << endl;
    formats.allNumbers();
    formats.monthFirst();
    formats.dayFirst();
    cout << endl;
}

//Ch 13 problem 2
void problem2()
{
    //Object with all the arguments declared
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    
    //Object with only 2 arguments declared(name and ID)
    Employee emp2("Mark Jones", 39119);
    
    //Object with no arguments declared
    Employee emp3;
    
    //Declaring missing arguments using mutator functions
    emp2.getDepartment("IT");
    emp2.getPosition("Programmer");
    
    emp3.getName("Joy Rogers");
    emp3.getId(81774);
    emp3.getDepartment("Manufacturing");
    emp3.getPosition("Engineer");
    
    //Printing employees data
    cout << "\nEmployee 1:" << endl;
    cout << "Name:       " << emp1.printName() << endl;
    cout << "ID:         " << emp1.printId() << endl;
    cout << "Department: " << emp1.printDepartment() << endl;
    cout << "Position:   " << emp1.printPosition() << endl;
    cout << "\nEmployee 2:" << endl;
    cout << "Name:       " << emp2.printName() << endl;
    cout << "ID:         " << emp2.printId() << endl;
    cout << "Department: " << emp2.printDepartment() << endl;
    cout << "Position:   " << emp2.printPosition() << endl;
    cout << "\nEmployee 3:" << endl;
    cout << "Name:       " << emp3.printName() << endl;
    cout << "ID:         " << emp3.printId() << endl;
    cout << "Department: " << emp3.printDepartment() << endl;
    cout << "Position:   " << emp3.printPosition() << endl;
    cout << endl;
}

//Ch 13 problem 4
void problem3()
{
    string name;      //Variable to get the user name
    string address;   //Variable to get the user address
    int age;          //Variable to get the user age
    string phone;     //Variable to get the user phone number
    
    //Declaring class objects
    PersonalInfo person1;
    PersonalInfo person2;
    PersonalInfo person3;
    
    //Getting user input and storing data using the function mutators
    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, name);
    person1.getName(name);
    cout << "Enter your address: ";
    getline(cin, address);
    person1.getAddress(address);
    cout << "Enter your age: ";
    cin >> age;
    person1.getAge(age);
    cout << "Enter your phone number: ";
    cin >> phone;
    person1.getPhone(phone);
    
    cout << "\nEnter your friends name: ";
    cin.ignore();
    getline(cin, name);
    person2.getName(name);
    cout << "Enter your friends address: ";
    getline(cin, address);
    person2.getAddress(address);
    cout << "Enter your friends age: ";
    cin >> age;
    person2.getAge(age);
    cout << "Enter your friends phone number: ";
    cin >> phone;
    person2.getPhone(phone);
    
    cout << "\nEnter your second friends name: ";
    cin.ignore();
    getline(cin, name);
    person3.getName(name);
    cout << "Enter your second friends address: ";
    getline(cin, address);
    person3.getAddress(address);
    cout << "Enter your second friends age: ";
    cin >> age;
    person3.getAge(age);
    cout << "Enter your second friends phone number: ";
    cin >> phone;
    person3.getPhone(phone);
    
    //Printing the information using the accessor function
    cout << endl;
    cout << person1.printName()<<" Information:" << endl;
    cout << "Address:      "     <<person1.printAddress() << endl;
    cout << "Age:          "         <<person1.printAge() << endl;
    cout << "Phone number: "<<person1.printPhone() << endl;
    
    cout << endl;
    cout << person2.printName()<<" Information:" << endl;
    cout << "Address:      "     <<person2.printAddress() << endl;
    cout << "Age:          "         <<person2.printAge() << endl;
    cout << "Phone number: "<<person2.printPhone() << endl;
    
    cout << endl;
    cout << person3.printName()<<" Information:" << endl;
    cout << "Address:      "     <<person3.printAddress() << endl;
    cout << "Age:          "         <<person3.printAge() << endl;
    cout << "Phone number: "<<person3.printPhone() << endl;
    
    cout << endl;
}

//Ch 13 problem 7
void problem4()
{
    Widget order;        //Widget object declaration
    float orderNumber;   //Number of widgets ordered
    
    //Getting input using the mutator functions
    cout << "\nHow many widgets have been ordered? ";
    cin >> orderNumber;
    while(orderNumber < 0)
    {
        cout << "\nInvalid input!" << endl;
        cout << "\nHow many widgets have been ordered? ";
        cin >> orderNumber;
    }
    order.getWidgets(orderNumber);
    
    //Printing the result using the accessor function
    cout << "\nThe manufacturing plant will take ";
    cout << order.getDays() << " days to manufacture that amount of widgets";
    cout << endl << endl;
}

//Ch 13 problem 12
void problem5()
{
    int size = 7;             //Number of employees
    Payroll employee[size];   //Object array for the employees
    float rate;               //Hourly pay rate for each employee
    float hours;              //Hours worked during the week for each employee
    
    //Loop to get the employee's pay info
    for(int i = 0; i < size; i++)
    {
        cout << "\nEnter the hourly pay rate of employee " << i+1 << ": ";
        cin >> rate;
        employee[i].getRate(rate);
        cout << "Enter the hours worked for the week: ";
        cin >> hours;
        while(hours > 60)
        {
            cout << "\nInvalid input. Hours cannot exceed 60!" << endl;
            cout << "Enter the hours worked for the week: ";
            cin >> hours;
        }
        employee[i].getHours(hours);
    }
    
    //Loop to print the gross pay earned for each employee
    for(int i = 0; i < size; i++)
    {
        cout << "\nEmployee " << i+1 << " earned a gross pay of: $";
        cout << employee[i].printTotal();
    }
    
    cout << endl << endl;
}

//Ch 14 problem 2
void problem6()
{
    int day;   //Number of days
    
    //Requesting input from user
    cout << "\nEnter a number from 1 to 365: ";
    cin >> day;
    while(day < 1 || day > 365)
    {
        cout << "\nInvalid input!" << endl;
        cout << "Enter a number from 1 to 365: ";
    cin >> day;
    }
    
    //Declaring class object
    DayOfYear numbers(day);
    
    //Calling class function to print result
    numbers.print();
    
    cout << endl;
}

//Ch 14 problem 4
void problem7()
{
    float hours = 0; //User input hours

    //Request user input
    cout << "Enter the hours for shift 1: ";
    cin >> hours;
    NumDays shift1(hours);
    cout << "Enter the hours for shift 2: ";
    cin >> hours;
    NumDays shift2(hours);

    //Printing days of work
    cout << endl;
    cout << shift1.getHour() << " hours is " << shift1.getDay() 
         << " days of work." << endl;
    cout << shift2.getHour() << " hours is " << shift2.getDay() 
         << " days of work." << endl;
    
    //Addition operator
    NumDays shift3 = shift1 + shift2;
    cout << "\nThe sum of shift 1 and 2 is: " << shift3.getDay();

    //Subtraction operator
    shift3 = shift1 - shift2;
    cout << "\nThe substraction of shift 1 and 2 is: " << shift3.getDay();

    cout << endl;
    
    //Prefix ++ operator
    ++shift3;
    cout<<"\nPrefix ++ is: "<<shift3.getDay();

    //Postfix ++ operator
    shift3++;
    cout<<"\nPostfix ++ is: "<<shift3.getDay();

    //Prefix -- operator
    --shift3;
    cout<<"\nPrefix -- is: "<<shift3.getDay();

    //Postfix -- operator
    shift3--;
    cout<<"\nPostfix -- is: "<<shift3.getDay();

    cout << endl << endl;
}

//Ch 14 problem 9
void problem8()
{
    int feet, inches; // To hold input for feet and inches  

    // Create two FeetInches objects. The default arguments 
    // for the constructor will be used. 
    FeetInches first, second; 

    // Get a distance from the user. 
    cout << "Enter a distance in feet and inches: "; 
    cin >> feet >> inches; 
    
    // Store the distance in first. 1
    first.setFeet(feet); 
    first.setInches(inches); 

    // Get another distance. 23 
    cout << "Enter another distance in feet and inches: "; 
    cin >> feet >> inches; 

    // Store the distance in second. 
    second.setFeet(feet); 
    second.setInches(inches); 

    cout << endl;
    
    // Compare the two objects. 
    if (first <= second) 
    cout << "first is less or equal to second.\n"; 
    if (first >= second) 
    cout << "first is greater or equal to second.\n"; 
    if (first != second) 
    cout << "first is not equal to second.\n"; 
    
    cout << endl;
}

//Ch 14 problem 11
void problem9()
{
    int feet, inches; // To hold input for feet and inches  

    // Create two FeetInches objects. The default arguments 
    // for the constructor will be used. 
    FeetInches first; 

    // Get a distance from the user. 
    cout <<"\nThis program uses a copy constructor to create a copy of a class"
            "object.\nThen the program will use the overload * operator to"
            "multiply both objects and display the result." << endl << endl;
    cout << "Enter a distance in feet and inches: "; 
    cin >> feet >> inches; 
    
    // Store the distance in first. 1
    first.setFeet(feet); 
    first.setInches(inches); 
    
    //Creating the copy
    FeetInches second(first);
    
    //Multiplying the objects
    FeetInches third = first * second;
    
    cout <<"\nThe multiplication of the original object and the copy is: ";
    cout << third.getFeet() << " feet " << third.getInches() << " inches";
    
    cout << endl << endl;
}

//Ch 14 problem 11
void problem10()
{
    int feet, inches; // To hold input for feet and inches  

  
    LandTract land;   //Object to use with the FeetInches class
    
    // Get a distance from the user. 
    cout << "Enter the length in feet and inches of the land: "; 
    cin >> feet >> inches; 
    land.getLength(feet, inches);
    
    cout << "Enter the width in feet and inches of the land: "; 
    cin >> feet >> inches; 
    land.getWidth(feet, inches);
    
    land.printArea();
    cout << endl;
}