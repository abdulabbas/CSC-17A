/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Project Two 
 * PIG DICE GAME
 * 3rd Edition
 * Created on October 14, 2015, 1:09 PM
 */
#include "Dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void Dice::rolling() {
    time_t t1, t2;
    cout << endl << "rolling." << flush;
    for (int x = 0; x < 3; x++) {
        t1 = time(0);
        do {
            t2 = time(0);
        } while (difftime (t2, t1) < 1);
        cout << "." << flush;
    }
}
void Dice::holding() {
    time_t t1, t2;
    cout << endl << "holding." << flush;
    for (int x = 0; x < 3; x++) {
        t1 = time(0);
        do {
            t2 = time(0);
        } while (difftime (t2, t1) < 1);
        cout << "." << flush;
    }
}
void FancyDice::face1() {
    cout << "                    ------- " <<endl;
    cout << "                   |       |" <<endl;
    cout << "                   |   @   |" <<endl;
    cout << "                   |       |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void FancyDice::face2() {
    cout << "                    ------- " <<endl;
    cout << "                   |       |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   |       |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void FancyDice::face3() {
    cout << "                    ------- " <<endl;
    cout << "                   |     @ |" <<endl;
    cout << "                   |   @   |" <<endl;
    cout << "                   | @     |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void FancyDice::face4() {
    cout << "                    ------- " <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   |       |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void FancyDice::face5() {
    cout << "                    ------- " <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   |   @   |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void FancyDice::face6() {
    cout << "                    ------- " <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
