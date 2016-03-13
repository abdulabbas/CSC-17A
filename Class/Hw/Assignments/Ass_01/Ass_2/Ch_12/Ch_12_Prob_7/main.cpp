/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Ch_12_Prob_7 
 * Created on September 25, 2015, 12:44 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    string read, output;
    char ch;
    ifstream inFile;
    ofstream outFile;

    
    cout<<"Enter the file name where your sentences are in: ";
    //location: get.txt
    cin>>read;
    
    cout<<"Enter the file name where your new sentences will be saved: ";
    //location: out.txt
    cin>>output;
    
    inFile.open(read.c_str());
    outFile.open(output.c_str());
    
    if(inFile){
        
          inFile.get(ch);     
          outFile.put(toupper(ch));
        
        do{
            
            inFile.get(ch); 
            outFile.put(ch);
          
            if(ch=='.'){
               inFile.get(ch); 
               outFile.put(toupper(ch)); 
            }    
                      
        }while(inFile);
 
        inFile.close();
        outFile.close();
        cout<<"File conversion done.\n";
    }else
        cout<<"Cannot open file!";
        
   
    //Exit Stage Right
    return 0;
}