/* 
 * File:   card.cpp
 * Author: Abdul-Hakim
 * Purpose: Implementation for the Card Class
 * Created on November 8, 2015, 7:38 PM
 */


//User Library for the Specification
#include "Card.h"

Card::Card(char n){
    setNum(n);
    count++;
}

void Card::setNum(char n){
    if(n<1||n>52)number=1;
    else number=n;
}
        
char Card::faceVal(){
     char fValue[13]={'A','2','3','4','5','6',
                     '7','8','9','T','J','Q','K'};
     return fValue[(number-1)%13];
}

char Card::numVal(){
    char numVal=(number-1)%13+1;
    if(numVal>10)numVal=10;
    return numVal;
}

char Card::suit(){
    //Declare suit array
    char aSuit[4]={'S','H','C','D'};
    return aSuit[(number-1)/13];
}

