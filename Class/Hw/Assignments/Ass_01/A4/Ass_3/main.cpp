/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Home work assignment 4 on chapter 11
 * Created on September 28, 2015, 12:57 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;
//User Libraries
//Global constants
//Function Prototypes

// Structure for problem 1
struct MovieData
{
    string title;     // Holds the title of the movie
    string director;  // Holds the director's name
    int yearRelease;  // Holds the year the movie was released
    float runTime;    // Holds the running time of the movie(in minutes)
};
// Function to get the data for problem 1
void getMovieData(MovieData &a, int n)
{
    // Requesting inputs
    cin.ignore();
    cout << "Movie " << n << endl;
    cout << "Please enter the title of the movie: ";
    getline(cin, a.title);
    cout << "Please enter the director's name: ";
    getline(cin, a.director);
    cout << "Please enter the year it was released: ";
    cin >> a.yearRelease;
    cout << "Please enter the running time(in minutes): ";
    cin >> a.runTime;
    cout << endl;
}
// Function to print the data for problem 1
void displayMovieData(const MovieData &b)
{   // Prints the information in the structure
    cout << "Title:         " << b.title << endl;
    cout << "Director:      " << b.director << endl;
    cout << "Year Released: " << b.yearRelease << endl;
    cout << "Running Time:  " << b.runTime << endl;
    cout << endl;
}
// Main problem 1
void movieData()
{   // Declaring the MovieData variables
    MovieData movie1;
    MovieData movie2;
    int number1 = 1, number2 = 2;
    
    // Requesting movie data
    getMovieData(movie1, number1);
    getMovieData(movie2, number2);
    
    // Displaying movie data
    displayMovieData(movie1);
    displayMovieData(movie2);
}

// Structure for problem 3
struct SalesData
{
    string divisionName;     // Holds the division name
    float firstQuatSales;    // Total sales made in the first quarter
    float secondQuatSales;   // Total sales made in the second quarter
    float thirdQuatSales;    // Total sales made in the third quarter
    float fourthQuatSales;   // Total sales made in the fourth quarter
    float totalAnnualSales;  // The sum of all four quarters
    float averageQuatSales;  // Average of sales per quarter
};
// Function to get the data for problem 3
void getSalesData(SalesData &a)
{
    // Requesting inputs with input validation
    cin.ignore();
    cout << "Enter the division name(East, West, North or South) ";
    getline(cin, a.divisionName);
    cout << "Enter the First-Quarter Sales: ";
    cin >> a.firstQuatSales;
    while(a.firstQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.firstQuatSales;
    }
    cout << "Enter the Second-Quarter Sales: ";
    cin >> a.secondQuatSales;
    while(a.secondQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.secondQuatSales;
    }
    cout << "Enter the Third-Quarter Sales: ";
    cin >> a.thirdQuatSales;
    while(a.thirdQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.thirdQuatSales;
    }
    cout << "Enter the Fourth-Quarter Sales: ";
    cin >> a.fourthQuatSales;
    while(a.fourthQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.fourthQuatSales;
    }
    cout << endl;
}
// Function to calculate the total and average
void getTotalAndAverage(SalesData &b)
{
    // Calculate total annual sales
    b.totalAnnualSales = b.firstQuatSales + b.secondQuatSales + 
                         b.thirdQuatSales + b.fourthQuatSales;
    // Calculate average quarterly sales
    b.averageQuatSales = (b.firstQuatSales + b.secondQuatSales + 
                          b.thirdQuatSales + b.fourthQuatSales) / 4.0;
    // Printing the structure variables
    cout << "Division Name:             $" << b.divisionName;
    cout << "\nFirst-Quarter:             $" << b.firstQuatSales;
    cout << "\nSecond-Quarter:            $" << b.secondQuatSales;
    cout << "\nThird-Quarter:             $" << b.thirdQuatSales;
    cout << "\nFourth-Quarter:            $" << b.fourthQuatSales;
    cout << "\nTotal Annual Sales:        $" << b.totalAnnualSales;
    cout << "\nAverage Quarterly Sales:   $" << b.averageQuatSales;
    cout << endl << endl;
}
// Main problem 3
void CorporateSalesData()
{   // Declaring SalesData variables
    SalesData division1, division2, division3, division4;
    
    // Calling function to collect the data from the user
    getSalesData(division1);
    getSalesData(division2);
    getSalesData(division3);
    getSalesData(division4);
    
    // Calling function to calculate total annual sales, average and printing
    getTotalAndAverage(division1);
    getTotalAndAverage(division2);
    getTotalAndAverage(division3);
    getTotalAndAverage(division4);
}

// Structure for problem 4
struct Weather
{
    float totalRain,    // Holds the total rain in the month
          highTemp,     // Holds the highest temperature in the month
          lowTemp,      // Holds the lowest temperature in the month
          averageTemp;  // Hols the average temperature in the month
};
// Main function for problem 4
void weatherStatistics()
{
    const int SIZE = 12;      // Size of the array, 12 months
    Weather months[SIZE];     // Structure array to store data
    float yearRain = 0;       // Sum of rain for all 12 months
    float yearAverage = 0;    // Average temperature of all months
    float highestTemp = 0;    // Highest temperature in the year
    float lowestTemp = 140;   // Lowest temperature in the year. Set to max temp
    int highestMonth = 0;     // Month with the highest temperature
    int lowestMonth = 0;      // Month with the lowest temperature
    // Requesting data from the user
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Enter total rainfall for month " << i+1 << " : ";
        cin >> months[i].totalRain;
        cout << "Enter highest temperature in Fahrenheit: ";
        cin >> months[i].highTemp;
        while(months[i].highTemp < -100 || months[i].highTemp > 140)
        {
            cout << "\nTemperature has to be  between -100 and +140" << endl;
            cout << "Enter highest temperature in Fahrenheit: ";
            cin >> months[i].highTemp;
        }
        cout << "Enter lowest temperature in Fahrenheit: ";
        cin >> months[i].lowTemp;
        while(months[i].lowTemp < -100 || months[i].lowTemp > 140)
        {
            cout << "\nTemperature has to be  between -100 and +140" << endl;
            cout << "Enter lowest temperature in Fahrenheit: ";
            cin >> months[i].lowTemp;
        }
        months[i].averageTemp = (months[i].highTemp + months[i].lowTemp) / 2;
        cout << endl;
    }
    // Calculating total rainfall, highest and lowest temperature and the month
    for(int j = 0; j < SIZE; j++)
    {
        yearRain += months[j].totalRain;
        yearAverage += months[j].averageTemp;
        if(months[j].highTemp > highestTemp)
        {
            highestTemp = months[j].highTemp;
            highestMonth = j + 1;
        }
        if(months[j].lowTemp < lowestTemp)
        {
            lowestTemp = months[j].lowTemp;
            lowestMonth = j + 1;
        }
    }
    // Printing the data in the structure array
    cout << fixed << showpoint << setprecision(2);
    cout << "Total rainfall for the year is: " << yearRain;
    cout << "\nAverage rainfall for the year is: " << yearRain / SIZE;
    cout << "\nAverage temperatures for all months: " << yearAverage / SIZE;
    cout << "\nHighest temp occurred in the " << highestMonth << " month with " 
         << highestTemp << " degrees";
    cout << "\nLowest temp occurred in the " << lowestMonth << " month with " 
         << lowestTemp << " degrees";
    cout << endl;
}

// Structure for problem 5
struct WeatherMod
{
    float totalRain,    // Holds the total rain in the month
          highTemp,     // Holds the highest temperature in the month
          lowTemp,      // Holds the lowest temperature in the month
          averageTemp;  // Hols the average temperature in the month
};
// Enumerator for problem 5. Each enumerator declared to corresponding month
enum year {JANUARY = 1, FEBRUARY = 2, MARCH = 3, APRIL = 4, MAY = 5, JUNE = 6, 
           JULY = 7, AUGUST = 8, SEPTEMBER = 9, OCTOBER = 10, NOVEMNER = 11, 
           DECEMBER = 12};
// Main function for problem 4
void weatherStatisticsModification()
{
    const int SIZE = 12;      // Size of the array, 12 months
    WeatherMod months[SIZE];     // Structure array to store data
    float yearRain = 0;       // Sum of rain for all 12 months
    float yearAverage = 0;    // Average temperature of all months
    float highestTemp = 0;    // Highest temperature in the year
    float lowestTemp = 140;   // Lowest temperature in the year. Set to max temp
    int highestMonth = 0;     // Month with the highest temperature
    int lowestMonth = 0;      // Month with the lowest temperature
    // Requesting data from the user
    for(year calendar = JANUARY; calendar <= DECEMBER; 
                                 calendar = static_cast<year>(calendar+1))
    {
        cout << "Enter total rainfall for month " << calendar << " : ";
        cin >> months[calendar].totalRain;
        cout << "Enter highest temperature in Fahrenheit: ";
        cin >> months[calendar].highTemp;
        while(months[calendar].highTemp < -100 || 
              months[calendar].highTemp > 140)
        {
            cout << "\nTemperature has to be  between -100 and +140" << endl;
            cout << "Enter highest temperature in Fahrenheit: ";
            cin >> months[calendar].highTemp;
        }
        cout << "Enter lowest temperature in Fahrenheit: ";
        cin >> months[calendar].lowTemp;
        while(months[calendar].lowTemp < -100 || months[calendar].lowTemp > 140)
        {
            cout << "\nTemperature has to be  between -100 and +140" << endl;
            cout << "Enter lowest temperature in Fahrenheit: ";
            cin >> months[calendar].lowTemp;
        }
        months[calendar].averageTemp = (months[calendar].highTemp + 
        months[calendar].lowTemp) / 2;
        cout << endl;
    }
    // Calculating total rainfall, highest and lowest temperature and the month
    for(year calendar2 = JANUARY; calendar2 <= DECEMBER; 
                                  calendar2 = static_cast<year>(calendar2 + 1))
    {
        yearRain += months[calendar2].totalRain;
        yearAverage += months[calendar2].averageTemp;
        if(months[calendar2].highTemp > highestTemp)
        {
            highestTemp = months[calendar2].highTemp;
            highestMonth = calendar2;
        }
        if(months[calendar2].lowTemp < lowestTemp)
        {
            lowestTemp = months[calendar2].lowTemp;
            lowestMonth = calendar2;
        }
    }
    // Printing the data in the structure array
    cout << fixed << showpoint << setprecision(2);
    cout << "Total rainfall for the year is: " << yearRain;
    cout << "\nAverage rainfall for the year is: " << yearRain / SIZE;
    cout << "\nAverage temperatures for all months: " << yearAverage / SIZE;
    cout << "\nHighest temp occurred in the " << highestMonth << " month with " 
         << highestTemp << " degrees";
    cout << "\nLowest temp occurred in the " << lowestMonth << " month with " 
         << lowestTemp << " degrees";
    cout << endl;
}

// Structure for problem 6
struct SoccerPlayer
{
    string playerName;  // Holds the name of the player
    int playerNumber;   // Holds the number of the player
    int pointsScored;   // Holds the number of points scored by the player
};
// Main function for problem 6
void soccerScores()
{
    const int PLAYERS = 12;      // Number of players in the team
    SoccerPlayer team[PLAYERS];  // Array of structures for each player
    int totalPoints = 0;         // The entire team total points
    int topScore = 0;            // Holds the top score
    int arrayPosition;           // The position in the array of the top scorer
    
    // Getting input with input validation
    for(int i = 0; i < PLAYERS; i++)
    {   
        cin.ignore();
        cout << "Enter the name of player " << (i + 1) << " : ";
        getline(cin, team[i].playerName);
        cout << "Enter the player number: ";
        cin >> team[i].playerNumber;
        while(team[i].playerNumber < 0)
        {
            cout << "\nPlayer number cannot be a negative number" << endl;
            cout << "Enter the player number: ";
            cin >> team[i].playerNumber;
        }
        cout << "Enter the points scored by the player: ";
        cin >> team[i].pointsScored;
        while(team[i].pointsScored < 0)
        {
            cout << "\nPoints scored cannot be a negative number" << endl;
            cout << "Enter the points scored by the player: ";
            cin >> team[i].pointsScored;
        }
        cout << endl;
    }
        
    // Calculating the total points and the top scorer
    for(int j = 0; j < PLAYERS; j++)
    {
        totalPoints += team[j].pointsScored;
        if(team[j].pointsScored > topScore)
        {
            topScore = team[j].pointsScored;
            arrayPosition = j;
        }
    }   
        
        // Printing the team results in a table
        cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) 
             << "+" << setw(5) << "-" << setw(1) << "+" << setw(5) << "-" 
             << setw(1) << "+" << endl;
	cout << setfill(' ') << setw(1) << "|" << setw(15) << left 
             << "Player Name" << setw(1) << "|" << setw(5) << left << "Number" 
             << setw(1) << "|"  << setw(5) << left << "Score" << setw(1) << "|" 
             << endl;
	cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) 
             << "+" << setw(5) << "-" << setw(1) << "+" << setw(5) << "-" 
             << setw(1) << "+" << endl;
        for(int k = 0; k < PLAYERS; k++)
        {
            	cout << setfill(' ') << setw(1) << "|" << setw(15) << left 
                     << team[k].playerName << setw(1) << "|" << setw(5) << left 
                     << team[k].playerNumber << setw(1) << "|"  << setw(5) 
                     << left << team[k].pointsScored << setw(1) << "|" << endl;
                cout << setfill('-') << setw(1) << "+" << setw(15) << "-" 
                     << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" 
                     << setw(5) << "-" << setw(1) << "+" << endl;
        }
        cout << "TEAM TOTAL SCORE:  " << totalPoints << endl;
        cout << "TOP SCORER PLAYER: " << team[arrayPosition].playerName << endl;
    
}

//Structure for problem 9
struct Speaker 
{
    string name;         // Name of the speaker
    string phoneNumber;  // Phone number of the speaker
    string speakTopic;   // The topic of the speaker
    float fee;           // Fee charged to the speaker
};
// Main function for problem 9
void speakersBureau()
{
    const int SIZE = 10;
    Speaker info[SIZE];
    int menu;
    string menuName;
    
    do
    {
        cout << "Enter 1 to input speaker's data"
             << "\nEnter 2 to change speaker's data"
             << "\nEnter 3 to display all speaker's data"
             << "\nEnter 4 to EXIT" << endl;
        cin >> menu;
        cout << endl;
        
        // Input speaker's data
        if(menu == 1)
        {
            for(int i = 0; i < SIZE; i++)
            {
                cin.ignore();
                cout << "Enter speaker "<< (i+1) << " name: ";
                getline(cin, info[i].name);
                cout << "Enter speaker " << (i+1) << " phone number: ";
                getline(cin, info[i].phoneNumber);
                cout << "Enter speaker "<< (i+1) << " speaking topic: ";
                getline(cin, info[i].speakTopic);
                cout << "Enter speaker "<< (i+1) << " fee: ";
                cin >> info[i].fee;
                while(info[i].fee < 0)
                {
                    cout << "\nFee cannot be less than 0" << endl;
                    cout << "Enter speaker "<< (i+1) << " fee: ";
                    cin >> info[i].fee;
                }
                cout << endl;
            }
        }
        // Change speaker data
        else if(menu == 2)
        {
            cin.ignore();
            cout << "Enter the name of the speaker to change his/hers data: ";
            getline(cin, menuName);
            // Searching for that speaker
            for(int i = 0; i < SIZE; i++)
            {
                // If name was found edit data
                if(menuName == info[i].name)
                {
                    cout << "Enter " << info[i].name << "'s new name: ";
                    getline(cin, info[i].name);
                    cout << "Enter " << info[i].name << "'s new phone number: ";
                    getline(cin, info[i].phoneNumber);
                    cout << "Enter " << info[i].name << "'s new topic: ";
                    getline(cin, info[i].speakTopic);
                    cout << "Enter "<< info[i].name << "'s new fee: ";
                    cin >> info[i].fee;
                    // Exit loop if name was found
                    break;
                }
            }
            // If name was not found
            cout << "\nSpeaker was not found!";
            cout << endl;
        }
        // Printing all speaker's data
        else if(menu == 3)
        {
            cout << "Here are all the speakers data: " << endl;
            for(int i = 0; i < SIZE; i++)
            {
                cout << "\nSpeaker " << (i+1) << " name:   " << info[i].name;
                cout << "\nTelephone Number: " << info[i].phoneNumber;
                cout << "\nSpeaking Topic:   " << info[i].speakTopic;
                cout << "\nFee Required:     " << info[i].fee;
                cout << endl << endl;
            }
        }
        // Exit
        else if(menu == 4)
        {
            cout << "Exit program" << endl;
        }
        // Input validation
        else
        {
            cout << "Invalid input. Enter numbers: 1, 2, 3 or 4 Only.\n";
        }
        
    }while(menu != 4);
}

// Structure for problem 11
struct Budget
{
    float housing,       // Amount spend for the house
          utilities,     // Amount spend in utilities
          housExpenses,  // Amount spend in the house
          transport,     // Amount spend in transportation
          food,          // Amount spend in food
          medical,       // Amount spend in health care
          insurance,     // Amount spend in insurance
          entermnt,      // Amount spend in entertainment
          clothing,      // Amount spend in clothing
          miscel;        // Amount spend in miscellaneous stuff
};
// Function to get the user spend amount for problem 11
void getExpenses(Budget &a)
{
    // Requesting all the data from the user
    cout << "Enter amount spent for housing: ";
    cin >> a.housing;
    cout << "Enter amount spent for utilities: ";
    cin >> a.utilities;
    cout << "Enter amount spent for household expenses: ";
    cin >> a.housExpenses;
    cout << "Enter amount spent for transportation: ";
    cin >> a.transport;
    cout << "Enter amount spent for food: ";
    cin >> a.food;
    cout << "Enter amount spent for medical: ";
    cin >> a.medical;
    cout << "Enter amount spent for insurance: ";
    cin >> a.insurance;
    cout << "Enter amount spent for entertainment: ";
    cin >> a.entermnt;
    cout << "Enter amount spent for clothing: ";
    cin >> a.clothing;
    cout << "Enter amount spent for miscellaneous: ";
    cin >> a.miscel;
    cout << endl;
}
// Function to compare and display the user budget
void compDisplay(Budget g, Budget r)
{
    cout<<fixed<<showpoint<<setprecision(2);
    // Comparing expenses to budget and printing results
    cout << "On your housing expenses you are ";
    if(r.housing == g.housing) 
        cout << "right on your budget of " << g.housing << endl;
    else if(r.housing < g.housing)
        cout << (g.housing - r.housing) << " under your budget of " 
             << g.housing << endl;
    else if(r.housing > g.housing)
        cout << (r.housing - g.housing) << " over your budget of " 
             << g.housing << endl;
    
    cout << "On your utilities expenses you are ";
    if(r.utilities == g.utilities) 
        cout << "right on your budget of " << g.utilities << endl;
    else if(r.utilities < g.utilities)
        cout << (g.utilities - r.utilities) << " under your budget of " 
             << g.utilities << endl;
    else if(r.utilities > g.utilities)
        cout << (r.utilities - g.utilities) << " over your budget of " 
             << g.utilities << endl;
    
    cout << "On your house expenses you are ";
    if(r.housExpenses == g.housExpenses) 
        cout << "right on your budget of " << g.housExpenses << endl;
    else if(r.housExpenses < g.housExpenses)
        cout << (g.housExpenses - r.housExpenses) << " under your budget of " 
             << g.housExpenses << endl;
    else if(r.housExpenses > g.housExpenses)
        cout << (r.housExpenses - g.housExpenses) << " over your budget of " 
             << g.housExpenses << endl;
    
    cout << "On your transportation expenses you are ";
    if(r.transport == g.transport) 
        cout << "right on your budget of " << g.transport << endl;
    else if(r.transport < g.transport)
        cout << (g.transport - r.transport) << " under your budget of " 
             << g.transport << endl;
    else if(r.transport > g.transport)
        cout << (r.transport - g.transport) << " over your budget of " 
             << g.transport << endl;
    
    cout << "On your food expenses you are ";
    if(r.food == g.food) 
        cout << "right on your budget of " << g.food << endl;
    else if(r.food < g.food)
        cout << (g.food - r.food) << " under your budget of " 
             << g.food << endl;
    else if(r.food > g.food)
        cout << (r.food - g.food) << " over your budget of " 
             << g.food << endl;
    
    cout << "On your medical expenses you are ";
    if(r.medical == g.medical) 
        cout << "right on your budget of " << g.medical << endl;
    else if(r.medical < g.medical)
        cout << (g.medical - r.medical) << " under your budget of " 
             << g.medical << endl;
    else if(r.medical > g.medical)
        cout << (r.medical - g.medical) << " over your budget of " 
             << g.medical << endl;
    
    cout << "On your insurance expenses you are ";
    if(r.insurance == g.insurance) 
        cout << "right on your budget of " << g.insurance << endl;
    else if(r.insurance < g.insurance)
        cout << (g.insurance - r.insurance) << " under your budget of " 
             << g.insurance << endl;
    else if(r.insurance > g.insurance)
        cout << (r.insurance - g.insurance) << " over your budget of " 
             << g.insurance << endl;
   
    cout << "On your entertainment expenses you are ";
    if(r.entermnt == g.entermnt) 
        cout << "right on your budget of " << g.entermnt << endl;
    else if(r.entermnt < g.entermnt)
        cout << (g.entermnt - r.entermnt) << " under your budget of " 
             << g.entermnt << endl;
    else if(r.entermnt > g.entermnt)
        cout << (r.entermnt - g.entermnt) << " over your budget of " 
             << g.entermnt << endl;
   
    cout << "On your clothing expenses you are ";
    if(r.clothing == g.clothing) 
        cout << "right on your budget of " << g.clothing << endl;
    else if(r.clothing < g.clothing)
        cout << (g.clothing - r.clothing) << " under your budget of " 
             << g.clothing << endl;
    else if(r.clothing > g.clothing)
        cout << (r.clothing - g.clothing) << " over your budget of " 
             << g.clothing << endl;
   
    cout << "On your miscellaneous expenses you are ";
    if(r.miscel == g.miscel) 
        cout << "right on your budget of " << g.miscel << endl;
    else if(r.miscel < g.miscel)
        cout << (g.miscel - r.miscel) << " under your budget of " 
             << g.miscel << endl;
    else if(r.miscel > g.miscel)
        cout << (r.miscel - g.miscel) << " over your budget of " 
             << g.miscel << endl;
}
// Main function for problem 11
void monthlyBudget()
{
    Budget goal;      // What budget the user set to himself
    Budget reality;   // What the user ended up spending
    
    //Set budget amounts
    goal.housing = 500.0;
    goal.utilities = 150.0;
    goal.housExpenses = 65.0;
    goal.transport = 50.0;
    goal.food = 250.0;
    goal.medical = 30.0;
    goal.insurance = 100.0;
    goal.entermnt = 150.0;
    goal.clothing =  75.0;
    goal.miscel =  50.0;
    
    getExpenses(reality);       // Get user input
    compDisplay(goal, reality); // Display results
}


//Execution begins here!
int main(int argc, char** argv) {
 // Declaring variables
    int problemNumber;
    char cont = 'N';
    // Menu loop to select the problem
    do
    {
	cout << "\nPlease enter the number of the problem you "
                "would like to run or press '0' to exit\n";
	cout << "\t1 = 11.1\n\t2 = 11.3\n\t3 = 11.4\n"
                "\t4 = 10.5\n\t5 = 11.6\n\t6 = 11.9\n\t"
                "7 = 11.11\n\t0 = EXIT" << endl;
	cin >> problemNumber;
	// Loop in case the user wants to run the same problem
	do
	{
            switch (problemNumber)
            {
                case 1: movieData(); break;
                case 2: CorporateSalesData(); break;
                case 3: weatherStatistics(); break;
                case 4: weatherStatisticsModification(); break;
                case 5: soccerScores(); break;
                case 6: speakersBureau(); break;
                case 7: monthlyBudget(); break;
		case 0: break;
		default: cout<<"That's an invalid entry\n"; break;
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
