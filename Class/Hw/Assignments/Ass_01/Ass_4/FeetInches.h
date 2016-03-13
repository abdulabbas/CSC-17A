/* 
 * File:   FeetInches.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 8:46 AM
 */

#ifndef FEETINCHES_H
#define	FEETINCHES_H

class FeetInches{
    private:
        int feet;          // To hold a number of feet 
        int inches;        // To hold a number of inches 
        void simplify();   // Defined in FeetInches.cpp 
    public:
        // Constructor 
        FeetInches(int f = 0, int i = 0)
        { 
            feet = f; 
            inches = i; 
            simplify(); 
        }
        
        //Copy Constructor
        FeetInches(const FeetInches &obj) 
        { 
            feet = obj.feet; 
            inches = obj.inches;
            simplify();
        }

        // Mutator functions 
        void setFeet(int f) { feet = f; } 
        void setInches(int i) 
        { 
            inches = i; 
            simplify(); 
        }
        
        // Accessor functions 
        int getFeet() const { return feet; } 
        int getInches() const { return inches; } 
        
        // Overloaded * operator
        FeetInches operator * (const FeetInches &); 

        // Overloaded operator functions
        bool operator>=(const FeetInches&);
        bool operator<=(const FeetInches&);
        bool operator!=(const FeetInches&);

};
 /*
 FeetInches operator + (const FeetInches &); // Overloaded + 
 FeetInches operator - (const FeetInches &); // Overloaded - 
 }; 
*/
 
#endif	/* FEETINCHES_H */

