/* 
 * File:   main.cpp
 * Author: Abdul-Hakim 
 * Purpose: Assignment 5  
 * Chapter 13 
 * Problems 
 * Created on November 17, 2015, 7:25 PM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
//User Libraries 
//Classes
#include "Date.h"
#include "Employee.h"
#include "PersonalInfo.h"
#include "Widget.h"
#include "Payroll.h"
using namespace std;
//Global constants
//Function Prototypes
//Problems Prototypes
void Menu();
int getN();
void def(int);
void problem1();   //Chapter 13 problem 1 
void problem2();   //Chapter 13 problem 2 
void problem3();   //Chapter 13 problem 4 
void problem4();   //Chapter 13 problem 7 
void problem5();   //Chapter 13 problem 12 

int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;   //Chapter 13 problem 1 
        case 2:    problem2();break;   //Chapter 13 problem 2 
        case 3:    problem3();break;   //Chapter 13 problem 4 
        case 4:    problem4();break;   //Chapter 13 problem 7 
        case 5:    problem5();break;   //Chapter 13 problem 12 
              default:   def(inN);}
    }while(inN>=1&&inN<=6);
        
    return 0;
}

void Menu(){
    cout<<"Menu for assignment 5"<<endl;
    cout<<"Type 1 for problem 13.1"<<endl;
    cout<<"Type 2 for problem 13.2"<<endl;
    cout<<"Type 3 for problem 13.4"<<endl;
    cout<<"Type 4 for problem 13.7"<<endl;
    cout<<"Type 5 for problem 13.12"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Assignment 5 
//Chapter 13 problem 1 
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

//Chapter 13 problem 2 
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

//Chapter 13 problem 4 
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

//Chapter 13 problem 7 
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

//Chapter 13 problem 12 
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
