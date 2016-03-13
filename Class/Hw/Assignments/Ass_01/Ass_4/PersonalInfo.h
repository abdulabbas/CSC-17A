/* 
 * File:   PersonalInfo.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 8:44 AM
 */

#ifndef PERSONALINFO_H
#define	PERSONALINFO_H
#include <string>

using namespace std;

class PersonalInfo 
{
    private:
        string name;      //Holds the name
	string address;   //Holds the address
	int age;          //Holds the age
	string phone;  	  //Holds the phone number	
    public:
        PersonalInfo();                //Default constructor
	void getName(string);          //Mutator to get the name
	void getAddress(string);       //Mutator to get the address
	void getAge(int);              //Mutator to get the age age
	void getPhone(string);         //Mutator to get the phone number
	string printName() const;      //Accessor to print the name
	string printAddress() const;   //Accessor to print address
	int printAge() const;          //Accessor to print the age
	string printPhone() const;     //Accessor to print the phone number
};

#endif	/* PERSONALINFO_H */

