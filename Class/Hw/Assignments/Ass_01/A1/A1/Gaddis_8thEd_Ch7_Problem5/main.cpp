/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Assignment 1
 * Created on July 24, 2015, 4:41 PM
 */


//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//User Libraries
//Global Constants
const int COLS=7;
//Function Prototypes
int read(char [],int [][COLS]);
void write(int [][COLS],int);
int min(int [][COLS],int);
int max(int [][COLS],int);
void avg(int [][COLS],int [],int);
//Execution begins here!
int main(int argc, char** argv) {
    //Declare variables
    const int ROWS=20;
    int mnkFood[ROWS][COLS];
    char fName[]="./monkey.dat";
    //Read the data from the file
    int actSize=read(fName,mnkFood);
    //Write the data
    write(mnkFood,actSize);
    //Output the minimum amount of food eaten by
    //a monkey
    cout<<"Smallest amount eaten by a monkey = "
        <<min(mnkFood,actSize)<<" ounces"<<endl;
    //Output the minimum amount of food eaten by
    //a monkey
    cout<<"Largest amount eaten by a monkey = "
        <<max(mnkFood,actSize)<<" ounces"<<endl;
    //Exit stage right
    return 0;
}

void avg(int [][COLS],int [],int){
    
}

int max(int monkey[][COLS],int ROWS){
    //Declare some small variable;
    int big=monkey[0][0];
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            if(big<monkey[row][col]){
                big=monkey[row][col];
            }
        }
    }
    return big;
}

int min(int monkey[][COLS],int ROWS){
    //Declare some small variable;
    int small=monkey[0][0];
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            if(small>monkey[row][col]){
                small=monkey[row][col];
            }
        }
    }
    return small;
}

void write(int monkey[][COLS],int ROWS){
    cout<<endl;
    cout<<"Monkey    M   T   W   T   F   S   S"<<endl;
    for(int row=0;row<ROWS;row++){
        cout<<"  "<<row+1<<"    ";
        for(int col=0;col<COLS;col++){
            cout<<setw(4)<<monkey[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}

int read(char fName[],int monkey[][COLS]){
    //Open the file
    ifstream input;
    input.open(fName);
    //Read the data
    int row=0;
    while(input){
        for(int col=0;col<COLS;col++){
                input>>monkey[row][col];
        }
        row++;
    }
    //Close the file
    input.close();
    //return the number of rows
    return --row;
}


