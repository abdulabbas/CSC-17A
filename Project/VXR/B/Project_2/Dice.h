/* 
 * File:   Dice.h
 * Author: Abdul-Hakim
 * Created on October 16, 2015, 10:51 AM
 */

#ifndef DICE_H
#define	DICE_H
class Dice {
public:
    void rolling();
    void holding();
};
class FancyDice: public Dice{
public:
    void face1();
    void face2();
    void face3();
    void face4();
    void face5();
    void face6();
};

#endif	/* DICE_H */


