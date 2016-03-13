/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Midterm CSC 17 A
 * Course Code: 48983 
 * Created on October 28, 2015, 8:06 AM
 */
//System libraries
#include <algorithm> //for sort function 
#include <iostream>
#include <string>
#include <iomanip>
//User libraries
#include"Bank.h"
using namespace std;
/*
 * Structures go here
*/
struct Employee {
    string name;
    int hours;
    int rate;
};
struct statsResult {
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
void print(int*, int, string ="");
/*
 *  Menu and problem prototypes
 */
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
//Function Prototypes
/*
 * Functions for problem 2
 */
int pay(Employee*);
void getEmpInfo(Employee*);
void formatCheck(Employee*, string);
bool validEmp(Employee *);
/*
 * Functions for problem 3
 */
statsResult *avgMedMode(int *,int);
void mode(statsResult*, int *,int );
void printSR(statsResult *);
/*
 * Functions for problem 4
 */
int *intArray(int, int=4);
int *encrypt(int *, int=4);
int *decrypt(int *, int=4);
void swap(int &a, int &);
bool isValid(int*, int =4);
/*
 * Functions for problem 5
 */
template<class T>
T factorial(T);
template<class T>
T maxFac(T);
/****************************************
 *
 *                  Main
 *
****************************************/
int main(int argc, const char * argv[]) {
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            default:   def(inN);}
        cout << endl;
    }while(inN>=1&&inN<=6);

    return 0;
}
void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}
int getN(){
    int inN;
    cin>>inN;
    return inN;
}
void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
//1)  Develop an application using structures for a customer
//that will determine if he/she has exceeded his/her checking 
//account balance. For each customer, the following 
//facts are available:
//
//a. Account number (Five digits only, i.e. test for this)
//b. Balance at the beginning of the month 
//c. Total of all checks written by this customer this month 
//     Loop until customer is through entering checks.
//d. Total of all deposits credited to this customer's account this 
//     month.  Loop until customer is through entering deposits.
//
//The program should input each of these facts from input dialogs as 
//integers, store in a structure, calculate the new balance, 
//display the new balance and debit the account $15 if overdrawn. 
//Also, if overdrawn, tell the customer the additional $15 fee 
//has been accessed and what the balance would be with this fee included.        
        Customer c;
        int nCheck;
        int temp;
        int len=0;//length of our account number
        do{
            cout<<"Input your account number (Five Digits ONLY!)\n";
            cin>>c.account;
            temp=c.account;
            for(len=0;temp>0;len++) {
                temp=temp/10;
            }
            if(len>5||len<5){
	        cout<<"Invalid Account number\n";
            }
        }while(len>5||len<5);        
        cout<<"Input the starting balance at the beginning of the month\n";
        cin>>c.start;
        cout<<"How many checks do you wish to write?\n";
        cin>>nCheck;
        for(int i=1;i<=nCheck;i++){
            cout<<"Input the total amount for check #"<<i<<endl;
            cin>>c.checks;
            c.start-=c.checks;
        }
        cout<<"How many checks do you wish to deposit?\n";
        cin>>nCheck;
        for(int i=1;i<=nCheck;i++){
            cout<<"Input the total amount deposited for check #"<<i<<endl;
            cin>>c.deposits;
            c.start+=c.deposits;
        }
        cout<<"Account number #"<<c.account<<endl;
        cout<<"Your balance is $"<<c.start<<endl;
        if(c.start<=0){
            cout<<"You have overdrafted from your account, we are going to charge $15 to your account\n";
                    c.start-=15;
                    cout<<"Your account balance including the overdraft is $"<<c.start<<endl;
        }
        cout<<endl;
}
//Employee pay 
//Problem # 2 
void problem2() {
    cout << "In problem 2\n\n";
    //create an array to hold employees
    //let user input the # of employees they want to input
    int nEmp;    
    cout<<"Enter the amount of employees that you would like to input?\n";
    cin>>nEmp;
    Employee **eArray = new Employee *[nEmp];
    for (int i = 0; i != nEmp; i++)
        *(eArray+i) = new Employee;
    cout << "Enter the date: ";
    string date;
    cin >> date;
    cout << endl;
    int count = 0;          
    // the number of employees entered 
    // get employee info
    // and print check while employee info is valid
    do {
        count++;
        getEmpInfo(*(eArray+count));
        if(validEmp(*(eArray+count)))
            formatCheck(*(eArray + count), date);
        else
            cout << "\nInvalid info. Goodbye\n";
    } while (validEmp(*(eArray+count)) && count != nEmp);

    for (int i = 0; i != nEmp; i++) {
        delete *(eArray+i);
    }
    delete []eArray;
}
// Mode problem
//Problem # 3 
void problem3() {
    cout << "In problem 3\n\n";
    int size;
    cout << "How many elements will you enter: ";
    cin >> size;    
    // create new array and fill with user supplied elements
    int *a = new int [size];
        for(int i=0;i<size;i++){
            cout << "Enter element " << i << ": ";
            int elem;
            cin >> elem;
            a[i] = elem;
        }
    cout << endl;
    // print what user entered 
    cout << "You entered:\n";
    print(a, size, " ");
    cout << endl;
    cout << endl;
    statsResult *sr = avgMedMode(a,size);    
    // calculate average 
    int total = 0;
    for (int i = 0; i != size; ++i)
        total += *(a+i);
    sr->avg=total / size;    
    printSR(sr);    
    // clean up
    delete []a;
    delete []sr->mode;
    delete sr;
}
// Enter a number. Encrypt it or decrypt it.
void problem4() {
    cout << "In problem 4\n\n";
    const int nDigit=4; // user is expected to enter a 4 digit number
    int num;
    do{
    cout << "Enter a four digit number: ";
    cin >> num;
    }while(num<1000||num>7777);
    int *numArray = intArray(num);
    // check if number is valid. No 8s or 9s
    if (isValid(numArray)) {
        // Ask user what to do with number
        cout << "Do you want your number encrypted or decrypted.\n"
                "Enter 1 to encrypt\n"
                "Enter 2 to decrypt\n";
        int ans;
        cin >> ans;
        // user want to encrypt number
        if (ans == 1) {
            numArray = encrypt(numArray);
            cout << "Your encrypted number is: ";
            print(numArray, nDigit);
        }
        // user wants to decrypt number
        else if (ans == 2) {
            numArray= decrypt(numArray);
            cout << "Your decrypted number is: ";
            print(numArray, nDigit);
        }
        else
            cout << "Invalid choice: ";
    }
    // number was not valid
    else {
        print(numArray, nDigit);
        cout << " is not valid.\n";
    }    
    delete []numArray;
    cout << endl;
}
// Function outputs the converions that were given
void problem6() {
    cout << "In problem 6\n";    
    cout << "a)\n";
    // 2.125 -> hex, binary, octal
    cout << "base: " << setw(6) << "10"<<
        setw(6) << "16"<<  setw(8) << "2"<< setw(6) << "8"<< endl;
    cout << setw(12) << "2.125"<<
    setw(6) << "2.2"<<  setw(8) << "10.001"<< setw(6) << "2.1"
    << endl;
    // -2.125 -> hex, binary, octal
    cout << setw(12) << "-2.125"<<
    setw(6) << "5.C"<<  setw(8) << "101.11"<< setw(6) << "5.6"
    << endl;    
    cout << "b)\n";
    cout << "46666601 = 1.09999991" << endl;
    cout << "46666602 = 2.19999981" << endl;
    cout << "B9999AFE = -0.58750045" << endl;    
}
// Function puts the n digits of a number into an array
// Uses default value of 4 as the input should be a 4 digit number
int *intArray(int num, int size) {
    // create the array to hold the numbers
    int *ret = new int [size];
    for (int i = size-1; i >= 0; --i) {
        ret[i] = num % 10;
        num /= 10;
    }
    return ret;
}
// For problem # 4 
// Function checks if the value supplied by the user is valid
bool isValid(int*array, int size) {
    for (int i = 0; i != size; ++i)
        // only 0 to 7 are allowed
        if (*(array+i) >7)
            return false;
    return true;
}

// Function encrypts an array of integers
// used for problem 4
int *encrypt(int *array, int size) {
    for (int i = 0; i != size; ++i){
        // first add three to each digit
        *(array+i) += 5;
        // then mod it by 8
        *(array+i) %= 8;
    }
    
    // swap elements 1,2 and 3,4
    swap(*(array), *(array+1));
    swap(*(array+2), *(array+3));

    return array;
}

// For problem 4
// Function decrypt a number supplied by the users
int *decrypt(int *array, int size) {
    // swap back elements 1,2 and 3,4
    swap(*(array), *(array+1));
    swap(*(array+2), *(array+3));
    
    // unmod the numbers
    for (int i = 0; i != size; ++i){
        if (*(array+i) <3)
            *(array+i) = 8 + *(array+i);
        else
            *(array+i) = *(array+i);
        // undo the addition
        *(array+i) -= 5;
    }
    return array;
}

// For problem 2
// Function get employee information
void getEmpInfo(Employee *e) {
    cout <<  "Enter the employee name: ";
    cin.ignore();
    getline(cin,e->name);
    cout << "Enter the pay rate: ";
    cin >> e->rate;
    cout << "Enter the hours worked: ";
    cin >> e->hours;
}

// For problem 2
// Function return true is employee rate and hours are greater than zero
bool validEmp(Employee *e) {
    if ( e->rate < 0 || e->hours < 0)
        return false;
    return true;
}

// For problem 2
// Function calculates the pay for an employee
int pay(Employee* e) {
    int r0=0;             // total pay
    int r1 = e->rate;     // r1 holds pay rate
    int r2 = e->hours;    // r2 holds hours worked
    int r3;               // temp
    int r4;               // holds the hours > than pay differential

    // check if triple time applies
    if ( r2 > 40) {
        r4 = r2 - 40;           // r4 holds hours > 40 worked
        r3 = r1 * 3;            // triple time pay
        r3 = r3 * r4;           // r3 holds that amount of triple time pay
        r2 = r2 - r4;           // move hours into double time
        r0 = r0 + r3;           // add to total pay
    }

    // check if double time applies
    if ( r2 > 20) {
        r4 = r2 - 20;           // r4 holds hours > 20 worked
        r3 = r1 * 2;            // double time pay
        r3 = r3 * r4;           // r3 holds that amount of double time pay
        r2 = r2 - r4;           // move hours into straight time
        r0 = r0 + r3;           // add to total pay
    }

    // check if straight time applies
    if ( r1 > 0) {
        r3 = r1 * r2;
        r0 = r0 + r3;
    }
    return r0;
}


// For problem # 2 
// Function prints a "check" for employee
void formatCheck(Employee *e, string date) {
    cout << setw(50) << right << date << endl << endl
    << left << "Pay to the order of: " << e->name
    << setw(25 - (e->name).size()) << right  << "$ " << pay(e) << endl;
    
    cout << endl;
}

//Problem # 5 
// Function outputs largest factorial for various data types
void problem5() {
    cout << "In problem 5\n\n";
    unsigned short uS;
    cout << "Largest unsigned short factorial is: " << maxFac(uS) << endl;
    signed short sS;
    cout << "Largest signed short factorial is: " << maxFac(sS) << endl;
    unsigned int uI;
    cout << "Largest unsigned int factorial is: " << maxFac(uI) << endl;
    signed int sI;
    cout << "Largest signed int factorial is: " << maxFac(sI) << endl;
    float fl;
    cout << "Largest float factorial is: " << maxFac(fl) << endl;  
    double dl;
    cout << "Largest double factorial is: " << maxFac(dl) << endl;
    long lr;
    cout << "Largest long factorial is: " << maxFac(lr) << endl;
    signed long sLr;
    cout << "Largest signed long factorial is: " << maxFac(sLr) << endl;
    unsigned long uLr;
    cout << "Largest unsigned long factorial is: " << maxFac(uLr) << endl;
      
}


// Function calculates factorials
template<class T>
T factorial(T n) {
    if (n==0)
        return 1;
    return n*factorial(n-1);
}

// Function calculates largest factorial for various data types
template<class T>
T maxFac(T) {
    T n=2; // can't use 1, factorial(1) == factorial(0)
    while (factorial(n-1) < factorial(n)) {
        ++n;
    }
    // current n overflows go back one
    return --n;
}



//Problem # 3 
statsResult *avgMedMode(int *array, int size) {
    statsResult *result = new statsResult;
    
    mode(result, array,size);

    return result;
    
}
//Problem # 3
void mode(statsResult* s, int *a,int n){
    //Create a parallel array to sort
    int *b=new int [n];
    
    for (int i=0; i !=n; ++i)
        b[i] = a[i];
    // sort the array
    sort(b, b+n);
    
    // for calculating median
    int mid = n /2;
    if ( n % 2 == 1)
        s->median = b[mid];
    else
        s->median = (b[mid] + b[mid-1])/2;

    //Count to max frequency
    int count=0,maxFreq=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq<count)maxFreq=count;
        }else{
            count=0;
        }
    }
    s->maxFreq=maxFreq+1;
    
    //cout<<"Max Freq = "<<maxFreq+1<<endl;
    //Count number of modes
    count=0;
    int nmodes=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq==count)nmodes++;
        }else{
            count=0;
        }
    }
    s->nModes=nmodes;
    //cout<<"Number of Modes = "<<nmodes<<endl;
    //Declare and fill the mode array
    s->mode =new int[nmodes];
    nmodes=0;
    count=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq==count)
                s->mode[nmodes++]=b[i];
        }else{
            count=0;
        }
    }
    
    //Clean up and return
    delete []b;
}

// For problem # 3 
// Function prints the statsResult structure
void printSR(statsResult* sr) {
    cout << "Median is : " << sr->median << endl;
    cout << "Average is : " << sr->avg << endl;
    cout<<"Number of modes = "<<sr->nModes<<endl;
    cout<<"The frequency of the modes = "<<sr->maxFreq<<endl;
    if(sr->nModes==0){
        cout<<"The mode set = {0}"<<endl;
    }else{
        cout<<"The mode set = {";
        print(sr->mode, sr->nModes-1, ",");
        // cout<<*(sr->mode+i)<<",";
        cout<<*(sr->mode + (sr->nModes-1))<<"}"<<endl;
    }
}

// Function swaps two values
void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Function prints out values of array 
void print(int *array, int size, string sep) {
    for (int i = 0; i != size; ++i) {
        cout << array[i] << sep;
    }
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}



/*
 * Spring Midterm 2015 CSC17A
Points for each question
1    15
2    15
3    20
4    20
5    10
6    20
7    10 ==> extra credit

Note: Submit the Midterm to my RCC email account mark.lehr@rcc.edu
with the following subject:  LastName,FirstName - Midterm - 48983

Submit the solutions/program in a zipped folder.  
Do the best you can and turn in as much as you can.  

Note:  I just want one program for the solution to all the problems 
that follow. The program should prompt the user for which problem 
solution to display. Use a do-while and switch construct somewhat
like the following for the display of the menu and the selection of
which problem to run

	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   def(inN);}
        }while(inN<8);

Note:  I have provided a program that implements this format.
All of your homework should use a similar structure.


1)  Develop an application using structures for a customer
that will determine if he/she has exceeded his/her checking 
account balance. For each customer, the following 
facts are available:

a. Account number (Five digits only, i.e. test for this)
b. Balance at the beginning of the month 
c. Total of all checks written by this customer this month 
     Loop until customer is through entering checks.
d. Total of all deposits credited to this customer's account this 
     month.  Loop until customer is through entering deposits.

The program should input each of these facts from input dialogs as 
integers, store in a structure, calculate the new balance, 
display the new balance and debit the account $15 if overdrawn. 
Also, if overdrawn, tell the customer the additional $15 fee 
has been accessed and what the balance would be with this fee included.


2)  Develop an application using an array of structures that will 
determine the gross pay for any number of employees input. The company pays 
"straight-time" for the first 40 hours worked, double time for 
all hours worked in excess of 40 hours but less than 50 hours, 
and triple time for any hours worked over 50 hours.

The program should be able to loop and input the employee's name, 
hours worked, and the rate of pay.  Once this has been done then 
the gross pay should be calculated.  Output all the pertinent information
with respect to the employee as a check and the process starts all over 
again until you input an invalid rate of pay or hours worked.  This
means a negative rate of pay or negative number of hours worked is
not acceptable.


3) Write a function using the following structure and prototype.

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

statsResult *avgMedMode(int *,int); 

The function takes in an integer array and the size of the array.
Then returns a pointer to a structure containing the average, median
and mode.  You will then write a printStat() function that will print
the results contained in the stats structure.  I will input a small 
array to test this out so ask for how many inputs to fill the array, 
then the values to place into the array.  Make sure you delete the 
dynamic array creation for the mode when you exit the problem.




4) A company wants to transmit data over the telephone, but they are 
concerned that their phones may be tapped. All of their data is 
transmitted as four-digit integers. However, they utilize the digits 
0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
will encrypt their data so that it may be transmitted more securely.
Your application should read a four-digit integer with the numbers 
0 to 7 entered by the user in an input dialog and encrypt it as 
follows: Replace each digit by (the sum of that digit plus 5) modulus 8. 
Then swap the first digit with the second, and swap the third digit 
with the fourth. Then print the encrypted integer. Write a separate 
application that inputs an encrypted four-digit integer and decrypts 
it to form the original number.
Note:  sometimes errors occur and the digits 8, and 9 might appear.  
Detect this condition and flag the error.  Can't read in numbers 
individually.  All the digits must be read with one cin statement.

6) a)  Convert the following 2 numbers to binary, octal and hex.
	2.125, 0.06640625
       When done, convert the following to a float representation.  
	-2.125, 0.06640625.  In other words, I want an 8 digit hex 
	number representation using the 4 byte float specification.
   b)  Convert the float representations of the following into 
	the decimal number.
	46666601, 46666602, B9999AFE

Note:  This doesn't require a program, however, I want you to write a 
simple function that outputs the answers you did by hand with "cout".

7) Factor an input integer into it's prime numbers.  Create a 
structure to hold the array of prime numbers.  Any number between
[2,10000] where n is not a prime > 100 will be a valid number to
check for prime factors.

struct Prime{
	unsigned char prime;
	unsigned char power;
};
struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};
Output the number and it's primes -> 120 = 2^3*3^1*5^1
So create a function 
Primes *factor(int);-> Input an integer, return all prime factors
void prntPrm(Primes *); -> Output all prime factors
 */


