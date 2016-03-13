/* 
 * File:   SavAccount.cpp 
 * Author: Abdul-Hakim 
 * Created on December 12, 2015, 11:23 AM 
 */

#include <cstdlib>
#include <iostream>

#include "SavAccount.h"

using namespace std;

SavAccount::SavAccount(float b)
{
    if(b < 0) 
    { 
        cout << "\nWithDraw not Allowed" << endl;
        Balance = 0;
    }
    else 
    { 
        Balance = b;
    }
    
    FreqWithDraw = 0;
    FreqDeposit = 0;
}

void  SavAccount::Transaction(float t)
{
    if(t > 0)
    {
        Balance += t;
        FreqDeposit++;
    }
    else if(t < 0)
    {
        if(t < Balance * -1)
        {
            cout << "WithDraw not Allowed" << endl;
        }
        else
        {
            Balance += t;
            FreqWithDraw++;
        }
    }
}

float SavAccount::Total(float savint,int time)
{
    float total = Balance;
    
    for(int i=0; i < time; i++)
    {
        total = total*(1+savint);
    }
    
    return total;
}

float SavAccount::TotalRecursive(float savint,int time)
{
    float total = Balance;
    float interest = 0.0;
    
    for(int i=0; i < time; i++)
    {
        interest = total * savint;
        total += interest;
    }
    
    return total; 
}

void  SavAccount::toString()
{
    cout << "\nBalance = " << Balance << endl;
    cout << "WithDraws = " << FreqWithDraw << endl;
    cout << "Deposits = " << FreqDeposit << endl;
}

