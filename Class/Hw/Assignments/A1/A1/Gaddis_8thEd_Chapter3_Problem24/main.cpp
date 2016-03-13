/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Homework from chapter 3
 * Created on July 4, 2015, 8:39 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
//Global Constants 
//Function Prototypes
//Execution Begins Here!
int main(int argc, char** argv) {
//Declare the variables
    string name;//Hold the name of the user
    string city;//Hold the name of the city
    string college;//Holds the name of the college
    string career;//Holds the occupation of the user
    string Animal;//Holds the type of animal that the user has adopted
    string Pet;//Holds the name of the pet
    int Age;//Holds the age of user when they were in college
//Prompt to let the user input the needed values
//This prompt is so the user can input their name
cout<<"Please enter your name:";
cin>>name;
//This prompt is so that the user can input the name of the city they live in    
cout<<"Enter the city you live in:";
cin>>city;
//This prompt is so the user the can input the name of the college that they attended
cout<<"Enter the name of the college that you attended:";
cin>>college;
//This prompt is so the user can input at which age they attended college
cout<<"Enter the age when you attended college:";
cin>>Age;
//This prompt is that the user can input the name of their profession
cout<<"Please enter the name of your career:";
cin>>career;
//This prompt is that the user can input the type of animal they adopted as a pet
cout<<"Enter the type of animal you have adopted as your pet:";
cin>>Animal;
//This prompt is the user can input the name of their pet
cout<<"Enter the name of your pet:";
cin>>Pet;
//Output the story 
//Which has the user inputs inserted in it
cout<<"There once was a person named "<<name<<" who lived in "<<city<<". "<<"At the age of "<<Age<<", "<<name<<" went to college at "<<college<<". "<<name<<" graduated and went to work as a "<<career<<". "<<"Then, "<<name<<" adopted a "<<Animal<<" named "<<Pet<<". "<<"They both lived happily ever after!"<<endl;
//Exit stage right
    return 0;
}

