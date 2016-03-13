/* 
 * File:   card.h
 * Author: Abdul-Hakim
 *
 * Created on October 15, 2015, 12:00 PM
 */

#ifndef CARD_H
#define	CARD_H

class Card{
    private:
        char number;
    public:
        Card(char);                       //Constructor
        void setNum(char);                //Mutator
        char getNum(){return number;}     //Accessor (in-line)
        char suit();                      //Suit property
        char numVal();                    //Numerical Value property
        char faceVal();                   //Face value property
};


#endif	/* CARD_H */

