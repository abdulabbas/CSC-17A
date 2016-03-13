/* 
 * File:   SavAccount.h 
 * Author: Abdul-Hakim 
 * Created on December 11, 2015, 9:32 PM 
 */

#ifndef SAVACCOUNT_H 
#define	SAVACCOUNT_H

class SavAccount 
{
    private:
	float Withdraw(float);               //Utility Procedure
	float Deposit(float);                //Utility Procedure
	float Balance;                       //Property
	int   FreqWithDraw;                  //Property
	int   FreqDeposit;                   //Property
    public:
	SavAccount(float);               //Constructor
	void  Transaction(float);            //Procedure
        float Total(float=0,int=0);	     //Savings Procedure
	float TotalRecursive(float=0,int=0);
	void  toString();                    //Output Properties
};


#endif	/* SAVACCOUNT_H */
//This is used for the Savings Account Problem 


