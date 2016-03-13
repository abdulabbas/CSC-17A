/* 
 * File:   PersonalInfo.cpp
 * Author: Abdul-Hakim
 * Created on September 28, 2015, 9:34 AM
 */


#include "PersonalInfo.h"

//Constructor to declare arguments to a default value
PersonalInfo::PersonalInfo()
{
    name = " ";
    address = " ";
    age = 0;
    phone = " ";
}

//Mutator for the name
void PersonalInfo::getName(string n){ name = n; }
//Mutator for the address
void PersonalInfo::getAddress(string ad){ address = ad; }
//Mutator for the age
void PersonalInfo::getAge(int ag){ age = ag; }
//Mutator for the phone
void PersonalInfo::getPhone(string p){ phone = p; }

//Accessor to print the name
string PersonalInfo::printName() const{ return name; }
//Accessor to print the address
string PersonalInfo::printAddress() const{ return address; }
//Accessor to print the age
int PersonalInfo::printAge() const{ return age; }
//Accessor to print the phone
string PersonalInfo::printPhone() const { return phone; }

