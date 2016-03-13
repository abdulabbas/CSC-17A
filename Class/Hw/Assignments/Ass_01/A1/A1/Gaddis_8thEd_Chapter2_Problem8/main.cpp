/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: To calculate the total purchase price of five items
 * Created on June 26, 2015, 11:27 PM
 */

#include <iostream>//File I/O

using namespace std;//std name space --> iostream

//User Libraries
//Global constants
//Function Prototypes
//Execution Begins here!
int main(int argc, char** argv) {
//Declare variables
    float item1;//Price of item one
    float item2;//Price of item two 
    float item3;//Price of item three 
    float item4;//Price of item four
    float item5;//Price of item five 
    float tPrice;//The total price of the items
//Process input here
item1 = 19.95;//Price of item one
item2 = 26.95;//Price of item two
item3 = 8.95;//Price of item three
item4 = 13.95;//Price of item four
item5 = 5.95;//Price of item five
tPrice = item1 + item2 + item3 + item4 + item5;//The total price of the items
//Output here
cout<<"The total purchase price is $"<<tPrice<<endl;
//Exit stage right!
    return 0;
}

