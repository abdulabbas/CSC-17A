/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Assignment 6
 * Chapter 14 
 * Problems 
 * Created on November 17, 2015, 9:44 PM
 */

//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
//User Libraries 
//Classes 
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
void problem1();//Chapter 14 problem 2 
void problem2();//Chapter 14 problem 4 
void problem3();//Chapter 14 problem 9 
void problem4();//Chapter 14 problem 11 
void problem5();//Chapter 14 problem 12 


int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;   //Chapter 14 problem 2  
        case 2:    problem2();break;   //Chapter 14 problem 4 
        case 3:    problem3();break;   //Chapter 14 problem 9 
        case 4:    problem4();break;   //Chapter 14 problem 11  
        case 5:    problem5();break;   //Chapter 14 problem 12 
              default:   def(inN);}
    }while(inN>=1&&inN<=6);
        
    return 0;
}

void Menu(){
    cout<<"Menu for assignment 6"<<endl;
    cout<<"Type 1 for problem 14.2"<<endl;
    cout<<"Type 2 for problem 14.4"<<endl;
    cout<<"Type 3 for problem 14.9"<<endl;
    cout<<"Type 4 for problem 14.11"<<endl;
    cout<<"Type 5 for problem 14.12"<<endl;
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
//Assignment 6 
//Chapter 14 problem 2 
void problem1()
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

//Chapter 14 problem 4
void problem2()
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

//Chapter 14 problem 9
void problem3()
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

//Chapter 14 problem 11
void problem4()
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

//Chapter 14 problem 12 
void problem5()
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
