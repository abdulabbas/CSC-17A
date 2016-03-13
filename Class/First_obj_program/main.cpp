/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: 1st object oriented program
 * Specifications
 * Created on October 15, 2015, 11:24 AM
 */
//system libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
//user libraries
#include "card.h"
using namespace std;
//Global constants
//Function Prototypes
//Execution starts here
int main(int argc, char** argv) {
//declare some variables
    

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<=53;i++){
        Card card(0);
        card.setNum(i);
        cout<<"Card Number = "<<static_cast<int>(card.getNum());
        cout<<" Suit = "<<card.suit();
        cout<<" Numerical Value = "<<static_cast<int>(card.numVal());
        cout<<" Face Value = "<<card.faceVal()<<endl;
    }

    return 0;
}
