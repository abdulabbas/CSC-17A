/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Assignment_2 
 * Created on September 25, 2015, 2:19 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
//User Libraries
using namespace std;
//Global Constants
//Function Prototypes for the problems

/********************************************************************
 *
 * Assignment 2
 *
 * ------------------------------------------------------------------
 * Menu selection program to run homework assignments:
 * 	10.1
 * 	10.2
 * 	10.3
 * 	10.4
 * 	10.5
 * 	12.1
 * 	12.2
 * 	12.4
 * 	12.6
 * 	12.7
 ********************************************************************/

// Functions for problems from chapter 10

//Count the number of characters in the string and ignores blanks
int length(char *charArray)
{
    int length = strlen(charArray);  // Getting the length
    int spaceCount = 0;              // Set counter to 0

    // Loop to count the spaces between words
    for(int i = 0; i <= length; i++)
    {
        if(charArray[i] == ' ')
        {
            spaceCount++;
        }
    }
    // Return the number of characters
    return (length - spaceCount);
}
// Reverses the letters in a string and displays it
void reverseString(char *charArray)
{
    // Calling the length function
    int stringLength = length(charArray);

    cout << "\nYour string backwards reads: \n";
    // Printing string backwards
    for(int i = (stringLength + 1); i >= 0; i--)
    {
        cout << charArray[i];
    }

    cout << endl;
}
// Counts the number of words in a phrase
int numberWords(string phrase)
{
    int count = 1;                 // Set counter to -1
    int length = phrase.length();  // Getting the length of the input

    //Count how many words
    for(int i = 0; i <= length; i++)
    {
        if(phrase[i] == ' ')
        {
            count++;
        }
    }
    // Returning the number of words
    return count;
}
// Capitalizes the first letter for each sentence
void sentenceCapitalizer(string phrase)
{
    int length = phrase.length();  // Getting the length of the input

    // Setting the first letter as upper case
    phrase[0] = toupper(phrase[0]);
    // Loop to capitalize the first letter after a period
    for(int i = 0; i <= length; i++)
    {
        if(phrase[i] == '.')
        {
            phrase[i + 2] = toupper(phrase[i + 2]);
        }
    }
    // Printing capitalized paragraph
    cout << "\nHere is your capitalized paragraph: " << endl;
    cout << phrase << endl;
}

// Chapter 10 problems

// Calculates the number of characters are in a c-string
void stringLenght()
{
    int size = 50;        // setting c-string size to 50
    char cString[size];   // c-string to hold the user input
    int count;            // holder for the function return

    cin.ignore();
    // Input a string
    cout << "\nInput a string and the program will give you the number of "
            "characters in the string" << endl;
    cin.getline(cString, size);

    // Calling the length function
    count = length(cString);
    // Display Functions Return Value
    cout << "The number of characters in the string is " << count << "." << endl;
}
void backwardString()
{
    int size = 100;         // setting c-string size to 100
    char charArray[size];   // c-string that holds the user input

    cin.ignore();
    // Input a string
    cout<<"\nInput a string and the program will display the string "
          "backwards" << endl;
    cin.getline(charArray, size);

    // Calling the reverse Function
    reverseString(charArray);
}
void wordCounter()
{
    string words;         // Strings to hold user input
    int wordCount;        // holder for the function return

    cin.ignore();
    // Input a string
    cout<<"\nInput a phrase and the program will give you the number of words in "
           "the phrase"<< endl;
    getline(cin, words);

    // Calling the word counter function
    wordCount = numberWords(words);
    // Printing the number of words
    cout << "\nYour phrase has "<< wordCount << " words."<< endl;
}
void averageNumberLetters()
{
    string words;          // string that holds the user input
    int wordCount;         // holder for the return of the numberWords function
    float totalLetters;    // The total number of letters int he string
    float letterAverage;   // The average of letters per word in the string

    cin.ignore();
    //Input a string
    cout << "\nInput a phrase and the program will calculate the average number of "
            "letters per word" << endl;
    getline(cin, words);
    // Calling the function
    wordCount = numberWords(words);
    // Calculating the size of the string
    totalLetters = words.length();
    // Calculating the average of letters per word
    letterAverage = (totalLetters - (wordCount - 1)) / wordCount;
    // Printing the result
    cout << setprecision(2) << fixed;
    cout << "\nThe average number of letters per word is "<< letterAverage
         << " letters."<< endl;
}
void sentenceCapitalizer()
{
    string uncapWords;  // String for the user input

    cin.ignore();
    cout << "\nInput a small paragraph in all lowercases. The program will "
         << "capitalize the first letter of each sentence" << endl;
    getline(cin, uncapWords);

    // Calling the word capitalizer function
    sentenceCapitalizer(uncapWords);
}

// Functions for problems from chapter 12

// Chapter 10 problems
void fileHead()
{
    fstream file;   // File to be open
    string name;    // Name of the file
    int count = 0;  // Set counter to 0

    cin.ignore();
    // Input the name of the file
    cout<<"What is the file name? ('numbers.txt') ";
    getline(cin,name);

    //Opens file name from the input
    file.open(name.c_str(), ios::in);
    if(file.fail())                    // Case the file fail to open
    {
        cout << "\nError opening the file" << endl;
    }

    while(file)   // Loop to print from the file
    {
        getline(file, name);

        if(file.eof() && count <= 10)  // If the file has less than 10 lines
        {
            cout << "\nThat's everything in the file" << endl;
            break;
        }
        else if(count == 10)
        {
            cout << "\nThe program is only displaying the first 10 lines\n";
            break;
        }
        // Print each line
        cout << name <<endl;
        count++;

    }
    file.close();
}
void fileDisplay()
{
    fstream file;  // File to be open
    string name;   // Name of the file
    int count = 0; // Set counter to 0

    cin.ignore();
    // Input file name
    cout<<"What is the file name? ('numbers.txt') ";
    getline(cin,name);

    //Opens file name from the input
    file.open(name.c_str(), ios::in);
    if(file.fail())
    {
        cout << "\nError opening the file" << endl;
    }

    while(file) // Loop to print from file
    {
        getline(file, name);

        if(count == 24) // Prints ever 24 lines
        {
            cout << "\nPress Enter to continue ";
            cin.get();
            count = 0;
        }

        // Printing each line
        cout << name <<endl;
        count++;
    }
    file.close();
}
void tailProgram()
{
    fstream file;  // File to be Open
    string name;   // Name of the file
    int size = 1000;  // Setting size of string array to 1000
    string nameArray[size];  // String array to store the data from file
    int count = 0;           // Setting counter to 0

    cin.ignore();
    // Input name of file
    cout<<"What is the file name? ('numbers.txt') ";
    getline(cin, name);

    //Opens file name from the input
    file.open(name.c_str(),ios::in);
    if(file.fail())
    {
        cout << "\nError opening the file" << endl;
    }

    while(file) // Loading array
    {
        getline(file, nameArray[count]);
        count++;
    }
    count = (count - 1);
    if(count <= 10)  // Case the file has less than 10 lines
    {
        cout << "\nThis is everything in the file" << endl;
        for (int i = 0; i <= count; i++)
        {
            cout << nameArray[i] <<endl;
        }
    }
    else if(count > 10) // Printing the last 10 lines in file
    {
        cout << "\nThese are the last 10 lines" << endl;
        for(int f = (count - 10); f < count; f++)
        {
            cout << nameArray[f] <<endl;
        }
    }
    file.close();
}
void stringSearch()
{
    fstream file;    // File to be open
    string name;     // Name of the file
    int count = 1;   // Setting counter to 1
    string search;   // String to be search in the file
    int foundTimes = 0;  // Number of times the string was found
    int size = 100;     // size for the foundLines array
    int foundLines[size]; // Array to store the line number the string was found
    string browsing;      // String to read each line in the file

    cin.ignore();
    // Input file name
    cout<<"What is the file name? ('numbers.txt') ";
    getline(cin, name);

    //Opens file name from the input
    file.open(name.c_str(), ios::in);
    if(file.fail())
    {
        cout << "\nError opening the file" << endl;
    }
    // Input string to search
    cout << "\nWhat string would you like to search in the file? ";
    getline(cin, search);

    while(!file.eof())  // Loop to read file and compare
    {
        getline(file, browsing);
        if(browsing == search)
        {
            foundTimes++;
            foundLines[foundTimes] = count;
        }
        count++;
    }
    file.close();
    cout << endl;
    // Printing the number of times found and the line number it was found
    cout << search << " was found " << foundTimes << " in the file. In lines: ";
    for(int g = 1; g <= foundTimes; g++)
    {
        cout << foundLines[g] << " ";
    }
    cout << endl;
}
void sentenceFileter()
{
	ifstream fileInput;   // File to take input from
	ofstream fileOutput;  // File to output
	string nameInput;     // Input file name
	string nameOutput;    // Output file name
	string sentence;      // Temporarily stores the date from input file
	int length;           // Length of the string sentence

	cin.ignore();
	// Input file name
    cout << "What is the input file name? ('sentence.txt') ";
    getline(cin, nameInput);
    // Output file name
    cout << "\nWhat is the output file name? ('empty.txt') ";
    getline(cin, nameOutput);

    // Opens file name from the input
    fileInput.open(nameInput.c_str(),ios::in);
    if(fileInput.fail())
    {
        cout << "\nError opening the file" << endl;
    }
    if(fileInput) // Loads senetence string
    {
    	getline(fileInput, sentence);
    }
    fileInput.close();

    length = sentence.length();
    for (int i = 0; i <= length; i++) // Making all letters lower case
    {
    	sentence[i] = tolower(sentence[i]);
   	}
	sentence[0] = toupper(sentence[0]); // Making the first letter upper case
	//Count how many words
	for(int j = 0; j <= length; j++) // Making every letter after a period upper case
	{
	    if(sentence[j] == '.')
	    {
	    	sentence[j + 2] = toupper(sentence[j + 2]);
	    }
	 }
	// Open output file
	fileOutput.open(nameOutput.c_str(),ios::out);
	if(fileOutput.fail())
	{
		cout << "\nError opening the file" << endl;
	}

	if(fileOutput) // Printing string sentence into the output file
	{
	   	fileOutput << sentence;
	}
	fileOutput.close();

	 cout << "\nThe sentence from the input file has been fixed and saved in the output file " << endl;
}





//Execution Starts Here
int main(int argc, char** argv) {
		// Declaring variables
		int problemNumber;
		char cont = 'N';

		// Menu loop to select the problem
		do
		{
			cout << "\nPlease enter the number of the problem you "
                                "would like to run or press '0' to exit\n";
			cout << "\t1 = 10.1\n\t2 = 10.2\n\t3 = 10.3\n"
                                "\t4 = 10.4\n\t5 = 10.5\n\t6 = 12.1\n\t"
                                "7 = 12.2\n\t8 = 12.4\n\t9 = 12.6\n\t"
                                "10 = 12.7\n\t0 = EXIT" << endl;
			cin >> problemNumber;

			// Loop in case the user wants to run the same problem
			do
			{
				switch (problemNumber)
				{
				  case 1:
				  	  stringLenght();
				  	  break;
				  case 2:
				  	  backwardString();
					  break;
				  case 3:
				  	  wordCounter();
					  break;
				  case 4:
				  	  averageNumberLetters();
					  break;
				  case 5:
				  	  sentenceCapitalizer();
				  	  break;
                  case 6:
				  	  fileHead();
				  	  break;
				  case 7:
				  	  fileDisplay();
					  break;
				  case 8:
				  	  tailProgram();
					  break;
				  case 9:
				  	  stringSearch();
					  break;
				  case 10:
					  sentenceFileter();
				  	  break;
				  case 0:
				  	  break;
				  default:
					  cout<<"That's an invalid entry\n";
					  break;
				}
			}while(problemNumber < 1 || problemNumber > 10);

                        cout << "\nDo you want to run the "
                                "program again? ('Y' to "
                                "continue or any other key to "
                                "cancel) ";
				cin >> cont;

		}while(toupper(cont) == 'Y');

        return 0;
}
