/* 
 * File:   Payroll.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 8:43 AM
 */


#ifndef PAYROLL_H
#define	PAYROLL_H

class Payroll {
    private:
        float payRate;       //Hourly pay rate
        float hoursWorked;   //Hours worked during the week
        float totalPay;      //Total gross pay for the week
    public:
        Payroll();              //Constructor to declare the arguments
        void getRate(float);    //Mutator to get the pay rate
        void getHours(float);   //Mutator to get the hours worked
        float printTotal();     //Accessor to print the total pay for the week
};

#endif	/* PAYROLL_H */

