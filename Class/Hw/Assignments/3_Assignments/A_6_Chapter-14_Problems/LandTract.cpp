/* 
 * File:   LandTract.cpp 
 * Author: Abdul-Hakim 
 * Created on November 17, 2015, 10:18 PM 
 */

#include "LandTract.h"

using namespace std;

//Mutator
void LandTract::getLength(int f, int i)
{
    length.setFeet(f);
    length.setInches(i);
}
//Mutator
void LandTract::getWidth(int f, int i)
{
    width.setFeet(f);
    width.setInches(i);
}
//Accessor to print the area
void LandTract::printArea()
{
    FeetInches temp;
    
    temp = length * width;
    
    cout << "\nThe area of the land is: " << temp.getFeet() << " feet "; 
    cout << temp.getInches() << " inches." << endl;
}

