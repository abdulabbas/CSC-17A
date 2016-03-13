/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Project Two 
 * PIG DICE GAME
 * 3rd Edition
 * Created on October 14, 2015, 1:09 PM
 */
#include "Score.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Score::scoreBoard(int ps, int os) {
    potentialScore = ps;
    overallScore = os;
    cout << string( 32, '\n' );
    cout << "                    |User|" << endl << endl;
    cout << "Turn Total: " << potentialScore << " Score: " << overallScore << endl;
    cout << string( 26, '\n' );
}
void Score::compScoreBoard(int ps, int cos) {
    potentialScore = ps;
    compOverallScore = cos;
    cout << string( 32, '\n' );
    cout << "                  |Computer|" << endl << endl;
    cout << "Turn Total: " << potentialScore << " Score: " << compOverallScore << endl;
    cout << string( 26, '\n' );
}
void Score::clearScreen(int ps, int ds, int os) {
    potentialScore = ps;
    diceScore = ds;
    overallScore = os;
    cout << string( 15, '\n' );
    cout << "                    |User|" << endl << endl;
    cout << "Turn Total: " << potentialScore + diceScore << " Score: " << overallScore << endl;
}
void Score::compClearScreen(int ps, int ds, int cos) {
    potentialScore = ps;
    diceScore = ds;
    compOverallScore = cos;
    cout << string( 15, '\n' );
    cout << "                  |Computer|" << endl << endl;
    cout << "Turn Total: " << potentialScore + diceScore << " Score: " << compOverallScore << endl;
}