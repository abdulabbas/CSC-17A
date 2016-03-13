/* 
 * File:   Bank.h
 * Author: Abdul-Hakim
 * Created on October 30, 2015, 1:26 AM
 */

#ifndef BANK_H 
#define	BANK_H

struct Customer{
    int account; //holds account number
    int start; //holds balance at beginning of month
    int checks; //total of all checks written this month
    int deposits; //total of all deposits credited this month
};

#endif	/* BANK_H */

