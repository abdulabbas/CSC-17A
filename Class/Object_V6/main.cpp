/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Object_V6
 * Created on November 8, 2015, 7:25 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

//Global Constants
int Card::count=0;
std::string Card::bgd="BackgroundCardFile.jpg";

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare some variables
    srand(static_cast<unsigned int>(time(0)));
    Deck *deck=new Deck();//Dynamic Allocation

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    Hand hand;
    for(int i=0;i<5;i++){
        int num=deck->deal()+1;
        hand.receive(num);
        Card *card=new Card(hand.inspect(num));
        cout<<"Card Number = "<<static_cast<int>(card->getNum());
        cout<<" "<<num<<" ";
        cout<<" Suit = "<<card->suit();
        cout<<" Numerical Value = "<<static_cast<int>(card->numVal());
        cout<<" Face Value = "<<card->faceVal()<<endl;
        delete card;
    }
    cout<<"Number of card instances -> "<<Card::getCnt()<<endl;
    cout<<"Card Background file -> "<<Card::getBgd()<<endl;
    cout<<"Number of cards in the hand = "<<hand.getNCrd()<<endl;
    --hand;
    cout<<"Number of cards in the hand = "<<hand.getNCrd()<<endl;
    
    //Exit stage right! 
    delete deck;
    return 0;
}
