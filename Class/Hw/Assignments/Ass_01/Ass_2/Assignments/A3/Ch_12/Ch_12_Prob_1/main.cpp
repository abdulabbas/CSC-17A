/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Ch_12_Prob_1
 * Created on September 25, 2015, 12:30 AM
 */
//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    string fileName,line;
    fstream datFile;
    
    
    cout<<"Enter the name of your file: ";
    cin>>fileName;
            
    datFile.open(fileName.c_str(), ios::in);
    
    while(datFile>>line){
        cout<<line<<endl;
    }
    
    
    datFile.close();
    //Exit Stage Right
    return 0;
}


