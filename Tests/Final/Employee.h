/* 
 * File:   Employee.h 
 * Author: Abdul-Hakim 
 * Created on December 11, 2015, 9:32 PM
 */

#ifndef EMPLOYEE_H 
#define	EMPLOYEE_H
class Employee 
{
        private:
		double Tax(float);      //Utility Procedure
		char   MyName[20];      //Property
		char   JobTitle[20];    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property
        public:
		Employee(char[],char[],float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
};

#endif	/* EMPLOYEE_H */
//This is the Employee.h file
//It is used to solve that Problem 


