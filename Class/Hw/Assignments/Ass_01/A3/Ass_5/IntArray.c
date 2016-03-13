/* 
 * File:   IntArray.c
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 10:33 AM
 */

#include "IntArray.h"

using namespace std;

IntArray::IntArray(int s)
{
   arraySize = s;
   aptr = new int [s];
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

IntArray::IntArray(const IntArray &obj)
{
   arraySize = obj.arraySize;
   aptr = new int [arraySize];
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

IntArray::~IntArray()
{
   if (arraySize > 0)
      delete [] aptr;
}
