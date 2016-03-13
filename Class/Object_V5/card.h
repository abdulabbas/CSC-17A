/* 
 * File:   card.h
 * Author: Abdul-Hakim
 * Created on November 8, 2015, 7:32 PM
 */

#ifndef CARD_H
#define	CARD_H

#include <string>


class Card{
    private:
        char number;
        void setNum(char);                //Mutator / Utility
        static int count;                 //Count the number of objects
        static std::string bgd;           //Background File 
    public:
        Card(char);                       //Constructor
        char getNum(){return number;}     //Accessor (in-line)
        char suit();                      //Suit property
        char numVal();                    //Numerical Value property
        char faceVal();                   //Face value property
        static int getCnt(){return count;}//Retrieve the static count
        static std::string getBgd(){return bgd;}//Background file
};

#endif	/* CARD_H */

