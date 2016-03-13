/* 
 * File:   main.cpp
 * Author: AbdulHakim Abbas
 * Purpose: To find out which area is the safest to drive
 * Created on July 11, 2015, 4:10 PM
 */

//System Libraries
#include <iostream>     //I/O Library
#include <iomanip>      //Parametric Library
#include <string>       //String Library
using namespace std;    //I/O Library under standard name space

//User Libraries
//Global Constants
//Function Prototypes
int nAcdnts(string);//Get number of accidents function
void fndLwst(int, int, int, int, int);//Find lowest function
//Execution Begins Here!
int main(int argc, char** argv) {
//Declare variables
    float north;
    float south;
    float east;
    float west;
    float central;
//Output title
    cout << setw(39) << "* Safest Driving Area *\n";
    cout << setw(39) << "-----------------------\n";
    cout << "This program calculates which region of San Francisco had the\n"
            "fewest reported automobile collisions last year.\n";
    cout << endl;
//Call function "Number of accidents"
    for(int i = 1; i <= 5; i++)
    {
        switch(i)
        {
            case 1:
                north = nAcdnts("Northern bay area");
                break;
            case 2:
                south = nAcdnts("Southern bay area");
                break;
            case 3:
                east = nAcdnts("Eastern bay area");
                break;
            case 4:
                west = nAcdnts("Western bay area");
                break;   
            case 5:
                central = nAcdnts("Central bay area");
                break;
        } 
    }
//Call function "Find lowest"
    fndLwst(north, south, east, west, central);
//Exit stage right!    
    return 0;
}

int nAcdnts(string name)
{
//Declare variables
    int acdnts;    
//Prompt user for input
    cout << "Enter the number of accidents within the " << name << ": ";
    cin >> acdnts;    
//Validate input
    while(acdnts < 0)
    {
        cout << "\nERROR: The number of accidents must be a nonnegative number."
                "\nRe-enter the number of accidents: ";
        cin >> acdnts;
    }  
//Return the value
    return(acdnts);
}

void fndLwst(int north, int south, int east, int west, int central)
{
    cout << endl;
//Determine if North had least accidents
    if(north < south && north < east && north < west && north < central)
    {
        cout << "Safest Driving Area: Northern Bay Area (" << north <<
                " accidents last year)";
    }  
//Determine if South had least accidents
    else if(south < north && south < east && south < west && south < central)
    {
        cout << "Safest Driving Area: Southern Bay Area (" << south <<
                " accidents last year)";
    }   
//Determine if East had least accidents
    else if(east < north && east < south && east < west && east < central)
    {
        cout << "Safest Driving Area: Eastern Bay Area (" << east <<
                " accidents last year)";
    }
//Determine if West had least accidents
    else if(west < north && west < south && west < east && west < central)
    {
        cout << "Safest Driving Area: Western Bay Area (" << west <<
                " accidents last year)";
    }    
//Determine if Central had least accidents
    else
    {
        cout << "Safest Driving Area: Central Bay Area (" << central <<
                " accidents last year)";
    }
}

