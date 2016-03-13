/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Object_V5 
 * Created on November 8, 2015, 7:24 PM
 */

//System Libraries

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//User Libraries

#include "Card.h"
#include "Deck.h"

using namespace std;

//Global Constants

int Card::count=0;
std::string Card::bgd="BackgroundCardFile.jpg";

//Function Prototypes

//Execution begins here! 
int main(int argc, char** argv) {
    //Declare some variables
    srand(static_cast<unsigned int>(time(0)));
    Deck *deck=new Deck();//Dynamic Allocation

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<2*deck->getNCrd();i++){
        int num=deck->deal()+1;
        Card *card=new Card(num);
        cout<<"Card Number = "<<static_cast<int>(card->getNum());
        cout<<" "<<num<<" ";
        cout<<" Suit = "<<card->suit();
        cout<<" Numerical Value = "<<static_cast<int>(card->numVal());
        cout<<" Face Value = "<<card->faceVal()<<endl;
        delete card;
    }
    cout<<"Number of card instances -> "<<Card::getCnt()<<endl;
    cout<<"Card Background file -> "<<Card::getBgd()<<endl;
    
    //Exit stage right
    delete deck;
    return 0;
}
