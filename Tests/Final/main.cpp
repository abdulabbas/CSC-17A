/* 
 * File:   main.cpp 
 * Author: Abdul-Hakim 
 * Purpose: Final CSC 17 A 
 * Course Code: 48983 
 * Created on December 11, 2015, 2:31 PM 
 */

//System Libraries
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm> //It is for the sort function
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

//User Libraries
#include "P1rnd.h"
#include "Prob2Sort.h"
#include "SavAccount.h"
#include "Employee.h"
#include "P3table.h"

using namespace std;

//Structures go here 

//Menu & Problem Prototypes go here
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Function Prototypes go here

/****************************************
 *
 *                  Main
 *
 ****************************************/
int main(int argc, const char * argv[]) {
    int inN;
    do {
        Menu();
        inN = getN();
        switch (inN) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            default: def(inN);
        }
        cout << endl;
    } while (inN >= 1 && inN <= 6);

    return 0;
}

void Menu() {
    cout << "Menu for the Final" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4" << endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type anything else to exit \n" << endl;
}

int getN() {
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}

void problem1() {
    cout << "In problem # 1" << endl << endl;
    char n = 5;
    char rndseq[] = {16, 34, 57, 79, 127};
    int ntimes = 100000;
    P1rnd a(n, rndseq);
    for (int i = 1; i <= ntimes; i++) {
        a.randFromSet();
    }
    int *x = a.getFreq();
    char *y = a.getSet();
    for (int i = 0; i < n; i++) {
        cout << int(y[i]) << " occured " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
}


void problem2()
{
    cout<<"Problem 2, the sorting problem"<<endl;
Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
	{
            cout<<zc[i*16+j];
	}
    }
    delete []zc;
    cout<<endl;
}

void problem3() {
    int rows = 5;
    int cols = 6;
    P3table<int> tab("Problem3.txt", rows, cols);
    const int *naugT = tab.getTable();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    const int *augT = tab.getAugTable();
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }
}

void problem4() {
    cout << "In problem # 4" << endl << endl;
    SavAccount mine(-300);

    for (int i = 1; i <= 10; i++) {
        mine.Transaction((float) (rand() % 500)*(rand() % 3 - 1));
    }
    mine.toString();
    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((float) (0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((float) (0.10), 7)
            << " Recursive Calculation " << endl;
}

void problem5() {
    cout << "In problem # 5" << endl << endl;
    
    Employee Mark("Mark", "Boss", 215.50);
    
    Mark.setHoursWorked(-3);
    Mark.toString();
    
    Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHoursWorked(25));
    Mark.toString();
    
    Mark.CalculatePay(Mark.setHourlyRate(40.0), Mark.setHoursWorked(25));
    Mark.toString();
    
    Mark.CalculatePay(Mark.setHourlyRate(60.0), Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary", "VP", 50.0);
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(40));
    Mary.toString();
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(50));
    Mary.toString();
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(60));
    Mary.toString();
    
    cout<<"\n"<<endl;
}

void problem6() {
    cout << "a) 0.125" << endl
            << "Binary: " << 0.001 << endl
            << "Octal: " << 0.1 << endl
            << "Hex: " << 0.2 << endl << endl;

    cout << "b) 0.3" << endl
            << "Binary: " << "0.01001" << endl
            << "Octal: " << "0.2314" << endl
            << "Hex: " << "0.4CC" << endl << endl;

    cout << "c) 89.3" << endl
            << "Binary: " << "1011001.01001" << endl
            << "Octal: " << "131.2314" << endl
            << "Hex: " << "59.4CC" << endl << endl;

}


