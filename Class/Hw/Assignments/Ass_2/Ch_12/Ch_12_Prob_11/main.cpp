/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 25, 2015, 1:39 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
//User Libraries
#include "sales.h"
using namespace std;

//Global Constants
enum Divs {Northern, Southern, Western, Eastern};

//Function Prototypes
void dispDiv(Divs);

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    
    int qtr=4;
    int sales[qtr];
    Divs div;
    fstream inFile;
    
    inFile.open("data.txt", ios::in);
    
    for (div=Northern; div<=Eastern; div=static_cast<Divs>(div+1)){
        cout<<"Division: ";
        dispDiv(div);
        cout<<endl;
        
        for(int j=0; j<qtr; j++){
            cout<<"Enter Q"<<j+1<<" sales: $";
            cin>>sales[qtr];
        }
        cout<<endl;
    }
    
    
    inFile.close();
    //Exit Stage Right
    return 0;
}

void dispDiv(Divs d){
    switch(d){
        case Northern: cout<<"Northern";
        break;
        case Southern: cout<<"Southern";
        break;
        case Western:  cout<<"Western";
        break;
        case Eastern:  cout<<"Eastern";
    }
} 

