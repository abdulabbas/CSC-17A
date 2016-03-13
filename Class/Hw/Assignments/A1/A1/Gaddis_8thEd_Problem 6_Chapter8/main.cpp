/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Problem-6-Gaddis-8thEd-Chapter-8 
 * Created on July 22, 2015, 1:58 PM
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//User Libraries
//Global Constants
//Function prototypes
void selectionSort(string [], int);
void showArray(const string [] , int);

//Execution Begins Here!
int main(int argc, char** argv) {
const int NUM_NAMES=20;
string names[NUM_NAMES]={"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", "Weaver, Jim",
"Pore, Bob", "Rutherford, Greg", "Javens, Renee", "Harrison, Rose",
"Setzer, Cathy",
"Pike, Gordon", "Holland, Beth" };
// Insert your code to complete this program
for(int index=0;index<NUM_NAMES;index++)
cout<<setw(15)<<names[index]<<endl;
selectionSort(names,NUM_NAMES);
return 0;
}
//External Functions if needed
void selectionSort (string names[], int size){
int strtScn,minDex;
string minVal;

for (strtScn=0; strtScn<(size-1);strtScn++)
{
minVal=strtScn;
minVal=names[strtScn];
for (int index=strtScn+1;index<size;index++){
if (names[index]<minVal){
minVal=names[index];
minDex=index;
}
}
names[minDex]=names[strtScn];
names[strtScn]=minVal;
}
}


