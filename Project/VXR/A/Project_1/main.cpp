/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Project One 
 * PIG DICE GAME_V1
 * Created on October 14, 2015, 1:09 PM 
 */

//System Level Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

//User Level Libraries
//Global Constants
const int COLS = 2;
const float initbet = 0.0;
//Function Prototype
void rolling();
void diceArt1();
void diceArt2();
void diceArt3();
void diceArt4();
void diceArt5();
void diceArt6();
void holding();
struct ThrowResults {
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
ThrowResults *avgMedMode(int *,int);
int *fillArray(int, int);
int *sortArray(int *, int);
void printStat(ThrowResults);
enum Day {FRIDAY, SATURDAY, SUNDAY, THURSDAY, WEDNESDAY, TUEDSAY, MONDAY};
struct User {
    string name;
    int age;
    string race;
    string gender;
    Day favoriteDay;
    bool pass;
};
bool checkWin(const int, int, int, bool&, float = initbet);
bool checkLoss(const int, int, int, bool&, float = initbet);
void scoreBoard(int, int);
void compScoreBoard(int,int);
void clearScreen(int, int, int);
void compClearScreen(int,int, int);
float earnings(bool, float);
void sortArray(char [][COLS], int);
//Execution Begins Here!
int main(int argc, char** argv) {
    
    //declare main menu variables
    int choice;
    
    //main menu output
    cout << " =========================" << endl;
    cout << "||   PIG: THE DICE GAME  ||" << endl;
    cout << "||         PROGRAM       ||" << endl;
    cout << " =========================" << endl << endl << endl;
    cout << "1. Play Pig" << endl;
    cout << "2. How to Play" << endl;
    cout << "3. Dice Probability Checker" << endl;
    cout << "4. Are You Competant Enough to Run This Program?  Found Out! " << endl;
    cout << "5. Quit Program" << endl << endl << endl;
    
    cout << "Enter choice number and press [enter].";
    cin >> choice;
    
    //main menu w/ input validation
    switch (choice) {
            //Play the game
        case 1: {
            char playAgain; //for multiple games
            float moneyWon; //will be either positive/negative if win/lose
            int gamesPlayed = 0;    //keeps track of total games played
            float betHistory[10];   //holds all moneyWon values across games
            const int ROWS = 50;    //number of user turns (most likely will not exceed 50)
            char rollHistory[ROWS][COLS];   //array for displaying action ('R' or 'H') and dice value (1-6)
            int i = 0;  //counter for betHistory
            float total;    //will calculate sum of all moneyWon across games
            do {
                //declare variables
                float bet;  //will be positive value if user wins, negative if lose
                int dice;       //6-sided die
                short action;     //variable for roll or hold
                bool userTurn = true;   //user always gets first turn
                int compScore = 0;      //score of computer
                int userScore = 0;      //score of user
                const int GOAL = 5;   //whoever surpasses this score wins
                bool win = false;  //if true user won, game ends
                bool loss = false;  //if true user lost, game ends
                srand(static_cast<unsigned int>(time(0)));  //set rand() seed
                unsigned int sleep(unsigned int seconds);   //sleep() function setup
                int j = 0;  //counter for rollHistory
                
                //gamble
                cout << "Type how much money you want to bet: $";
                cin >> bet;
                //Game begins and turns proceed until game has ended
                while (win == false && loss == false) {
                    //when userTurn == true, it is user's turn to roll or hold
                    if (userTurn == true) {
                        //must reset turn total
                        int turnTotal = 0;
                        //must reset roll number
                        bool rolled = false;    //sees if user rolled at least one time (only used for "hold" input validation)
                        
                        do {
                            dice = rand() % 6 + 1;  //[1,6]
                            cout << endl;
                            cout << "Your turn: Type \"1\" to roll and \"2\" to hold: ";
                            cin >> action;
                            scoreBoard(turnTotal, userScore);
                            //if user picks "roll"
                            if (action == 1) {
                                rolling();
                                //if dice lands on 1, no value is banked and userTurn becomes false, meaning computer's turn starts
                                if (dice == 1){
                                    cout << string( 15, '\n' );
                                    cout << "                    |User|" << endl << endl;
                                    cout << "Turn Total: 0                         Score: " << userScore << endl;
                                    diceArt1();
                                    userTurn = false;
                                    cout << endl;
                                }
                                //if dice lands on value other than 1, that value is added to turn total
                                else if (dice == 2) {
                                    clearScreen(turnTotal, dice, userScore);
                                    diceArt2();
                                    turnTotal += dice;
                                    
                                }
                                else if (dice == 3) {
                                    clearScreen(turnTotal, dice, userScore);
                                    diceArt3();
                                    turnTotal += dice;
                                    
                                }
                                else if (dice == 4) {
                                    clearScreen(turnTotal, dice, userScore);
                                    diceArt4();
                                    turnTotal += dice;
                                    
                                }
                                else if (dice == 5) {
                                    clearScreen(turnTotal, dice, userScore);
                                    diceArt5();
                                    turnTotal += dice;
                                    
                                }
                                else if (dice == 6) {
                                    clearScreen(turnTotal, dice, userScore);
                                    diceArt6();
                                    turnTotal += dice;
                                    
                                }
                                checkWin(GOAL, turnTotal, userScore, win, bet);
                                rolled = true;
                                rollHistory[j][0] = 'R';
                                rollHistory[j][1] = dice + 48;
                                j++;
                            }
                            //if user picks "2"
                            else if (action == 2) {
                                //player must have rolled once before "hold" banks the turn total
                                if (rolled == true) {
                                    holding();
                                    //turn total is banked and added to the overall score of user
                                    userScore += turnTotal;
                                    turnTotal = 0;
                                    scoreBoard(turnTotal, userScore);
                                    userTurn = false;
                                    cout << "Banked your total.  " << endl;
                                }
                                //if player has not rolled once before selecting "hold," the program automatically rolls and similar if else statements from above activate
                                else if (rolled == false) {
                                    cout << "Cannot hold yet." << endl;
                                }
                                rollHistory[j][0] = 'H';
                                rollHistory[j][1] = '-';
                                j++;
                            }
                            else {
                                cout << "Please type a valid action of \"1\" or \"2.\"" << endl;
                            }
                            //user must have picked valid action, it must be the users turn, and the game must still be active (userScore < GOAL)
                        } while ((action == 1 || action == 2) && userTurn == true && win == false && loss == false);
                    }
                    //computer's turn (only input user does is pressing [enter])
                    else if (userTurn == false) {
                        
                        int turnTotal = 0;  //turnTotal is reset for computer
                        bool rolled = false;   //reset roll number
                        
                        cout << "Hit [enter] once to progress through the computer's turn.";
                        cin.ignore(2);
                        
                        do {
                            dice = rand() % 6 + 1;    //same dice and probability as user
                            int compAction = rand() % 4 + 1; //computer will roll 3 out of 4 times
                            compScoreBoard(turnTotal, compScore);
                            //roll action should happen 3 out of 4 times
                            if (compAction == 1 || compAction == 2 || compAction == 3) {
                                rolling();
                                if (dice == 1){
                                    cout << string( 15, '\n' );
                                    cout << "                  |Computer|" << endl << endl;
                                    cout << "Turn Total: 0                         Score: " << compScore << endl;
                                    diceArt1();
                                    userTurn = true;
                                    cout << endl;
                                    
                                }
                                else if (dice == 2) {
                                    compClearScreen(turnTotal, dice, compScore);
                                    diceArt2();
                                    turnTotal += dice;
                                    cout << endl;
                                    
                                }
                                else if (dice == 3) {
                                    compClearScreen(turnTotal, dice, compScore);
                                    diceArt3();
                                    turnTotal += dice;
                                    cout << endl;
                                }
                                else if (dice == 4) {
                                    compClearScreen(turnTotal, dice, compScore);
                                    diceArt4();
                                    turnTotal += dice;
                                    cout << endl;
                                }
                                else if (dice == 5) {
                                    compClearScreen(turnTotal, dice, compScore);
                                    diceArt5();
                                    turnTotal += dice;
                                    cout << endl;
                                }
                                else if (dice == 6) {
                                    compClearScreen(turnTotal, dice, compScore);
                                    diceArt6();
                                    turnTotal += dice;
                                    cout << endl;
                                }
                                checkLoss(GOAL, turnTotal, compScore, loss, bet);
                                rolled = true;
                            }
                            //hold action should happen 1 out of 4 times
                            else if (compAction == 4) {
                                if (rolled == true) {
                                    holding();
                                    compScore += turnTotal;
                                    turnTotal = 0;
                                    compScoreBoard(turnTotal, compScore);
                                    cout << "The computer has banked its turn total." << endl;
                                    userTurn = true;
                                }
                                else if (rolled == false) {
                                    rolling();
                                    //roll will happen automatically
                                    if (dice == 1){
                                        cout << string( 15, '\n' );
                                        cout << "                  |Computer|" << endl << endl;
                                        cout << "Turn Total: 0                         Score: " << compScore << endl;
                                        diceArt1();
                                        userTurn = true;
                                        cout << endl;
                                        
                                    }
                                    else if (dice == 2) {
                                        compClearScreen(turnTotal, dice, compScore);
                                        diceArt2();
                                        turnTotal += dice;
                                        cout << endl;
                                    }
                                    else if (dice == 3) {
                                        compClearScreen(turnTotal, dice, compScore);
                                        diceArt3();
                                        turnTotal += dice;
                                        cout << endl;
                                    }
                                    else if (dice == 4) {
                                        compClearScreen(turnTotal, dice, compScore);
                                        diceArt4();
                                        turnTotal += dice;
                                        cout << endl;
                                    }
                                    else if (dice == 5) {
                                        compClearScreen(turnTotal, dice, compScore);
                                        diceArt5();
                                        turnTotal += dice;
                                        cout << endl;
                                    }
                                    else if (dice == 6) {
                                        compClearScreen(turnTotal, dice, compScore);
                                        diceArt6();
                                        turnTotal += dice;
                                        cout << endl;
                                    }
                                    checkLoss(GOAL, turnTotal, compScore, loss, bet);
                                    rolled = true;
                                }
                                else {
                                    cout << "If you are seeing this, then something horribly wrong has happened.";
                                }
                                
                            }
                            else {
                                cout << "If you are seeing this, then something horribly wrong has happened." << endl;
                            }
                            //computer delay between turns
                            for (int x = 0; x < 2; x++) {
                                time_t t1, t2;
                                t1 = time(0);
                                do {
                                    t2 = time(0);
                                } while (difftime (t2, t1) < 1);
                            }
                        } while (userTurn == false && win == false && loss == false);
                    }
                }
                gamesPlayed++;
                
                cout << endl << "Rolls Stats:" << endl;
                cout << endl;
                sortArray(rollHistory, j);
                moneyWon = earnings(win, bet);
                betHistory[i] = moneyWon;
                i++;
                
                cout << "Play again?";
                cin >> playAgain;
            } while (toupper(playAgain) == 'Y');
            //writing all the money won and lost and total across games
            cout << "Gambling receipt has been printed to a file.";
            ofstream outputFile;
            outputFile.open("receipt.txt");
            for (int j = 0; j < gamesPlayed; j++) {
                outputFile << "Game: " << j + 1 << "       Money won: $ " << setw(8) << betHistory[j] << endl;
                total += betHistory[j];
            }
            outputFile << "                        ------------" << endl;
            outputFile << "                          " << setw(9) << total;
            outputFile.close();
        }
            break;
            
        //How to play
        case 2: {
            //Declare file to be read from
            fstream inFile;
            string word;
            cout << "==============================================================================" << endl;
            inFile.open("HowToPlay.txt", ios::in);
            if (inFile) {
                getline(inFile, word);
                while(inFile){
                    cout << word;
                    getline(inFile, word);
                }
                inFile.close();
            }
            else {
                cout << "error";
            }
            cout << endl << "=======================================" << endl;
            cout << endl;
        }
            
            break;
            
        //Dice throw checker (for users who are unsure of the probability of computer dice)
        case 3: {
            cout << endl;
            
            //Declare Variables
            char dice;
            int throws;
            char throwAgain;
            char throwAgain2;
            fstream binaryFile;
            
            //Set our random number seed
            srand(static_cast<unsigned int>(time(0)));
            
            //Repeat program?
            do {
                //Initialize each outcome
                int c[6] = {0,0,0,0,0,0};
                
                //Input the number of throws
                do {
                    cout << "How many times do you want to throw the 6-sides dice? ";
                    cin >> throws;
                    
                } while (!(throws > 0 && throws < 1e9));
                
                //Loop the number of times to throw the dice
                for(int roll = 1; roll <= throws; roll++) {
                    //Roll the dice
                    dice = rand() % 6 + 1;    //[1,6]
                    
                    //Determine occurrence of each throw
                    c[dice - 1]++;
                }
                //Write and Read to Binary File
                binaryFile.open("test.txt", ios::out | ios::binary);
                binaryFile.write(reinterpret_cast<char *>(c), sizeof(c));
                binaryFile.close();
                binaryFile.open("test.txt", ios::in | ios::binary);
                binaryFile.read(reinterpret_cast<char *>(c), sizeof(c));
                binaryFile.close();
                //Output the results
                for (int j = 0; j <= 5; j++) {
                    cout << j + 1 << " occurred " << c[j] << " times." << endl;
                }
                cout << "Would you like to roll again? ";
                cout << "Type Y for yes or N for no" << endl;
                cin >> throwAgain;
            } while (toupper(throwAgain) == 'Y');
            
            do {
                int sides;
                int throws = 0;
                cout << "Input number of sides on the randomly-sided dice: ";
                cin >> sides;
                do {
                    cout << "How many times do you want to throw the randomly-sided dice? ";
                    cin >> throws;
                    
                } while (!(throws > 0 && throws < 1e9));
                
                
                int *a = fillArray(throws, sides);
                ThrowResults *pointer = avgMedMode(a, throws);
                ThrowResults throwResults = *pointer;
                printStat(throwResults);
                delete []a;
                cout << "Would you like to roll again? ";
                cout << "Type Y for yes or N for no" << endl;
                cin >> throwAgain2;
            } while (toupper(throwAgain2) == 'Y');
            
            break;
        }
        //Competence tester
        case 4: {
            int numUsers;
            const int SERIES_SIZE = 3;
            char series[SERIES_SIZE];
            cout << "How many users will be particpating? :";
            cin >> numUsers;
            User *user;
            user = new User[numUsers];
            for (int i = 0; i < numUsers; i++) {
                bool competent = true;
                bool next = false;
                cin.ignore();
                cout << "Test for user " << i + 1 << ": " << endl;
                cout << "Input your name: ";
                getline(cin, user[i].name);
                cout << "Input your age: ";
                cin >> user[i].age;
                cin.ignore();
                cout << "Input your race: ";
                getline(cin, user[i].race);
                cout << "Input your gender: ";
                cin >> user[i].gender;
                cout << "Thank you. Now to start." << endl;
                cout << "If you can follow simple instructions than you should be able to run this program.  Let's give you a little test." << endl;
                while (competent == true && next == false) {
                    cout << "The first test is a simple question: What is your favorite day?  (Enter number)" << endl;
                    cout << "1)FRIDAY 2)SATURDAY 3)SUNDAY 4)THURSDAY 5)WEDNESDAY 6)TUEDSAY 7)MONDAY";
                    int x;
                    cin >> x;
                    user[i].favoriteDay = static_cast<Day>(x);
                    if (x > THURSDAY) {
                        competent = false;
                        cout << "No person likes weekdays over the weekend. You have failed." << endl;
                        break;
                    }
                    else {
                        cout << "Good. Now type a series without spaces. Type a symbol, followed by a digit, followed by an upper-case letter: ";
                        cin >> series;
                        cin.getline(series, SERIES_SIZE);
                        cout << endl;
                        if(!ispunct(series[0]) && !isdigit(series[1]) && !isupper(series[2])) {
                            competent = false;
                            cout << "You have failed" << endl;
                            break;
                        }
                        else {
                            user[i].pass = true;
                            cout << "Congratulations you have passed the test, you may move onto the program." << endl;
                            cout << " ====================================" << endl;
                            cout << "|       Certificate of Competence    |" << endl;
                            cout << "|          " << user[i].name << endl;
                            cout << "|              Great Job!            |" << endl;
                            cout << " ====================================" << endl;
                            next = true;
                        }
                    }
                    
                }
            }
            break;
        }
        //Quit program
        case 5: {
            cout << endl;
            cout << "Program ending." << endl;
        }
            break;
            
        //Input re-entry
        default: {
            cout << endl;
            cout << "Invalid entry. Restart program and enter (1-4)." << endl;
            
        }
    }
    
    return 0;
}
//delay in between rolls
void rolling() {
    time_t t1, t2;
    cout << endl << "rolling." << flush;
    for (int x = 0; x < 3; x++) {
        t1 = time(0);
        do {
            t2 = time(0);
        } while (difftime (t2, t1) < 1);
        cout << "." << flush;
    }
}

void diceArt1() {
    cout << "                    ------- " <<endl;
    cout << "                   |       |" <<endl;
    cout << "                   |   @   |" <<endl;
    cout << "                   |       |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void diceArt2() {
    cout << "                    ------- " <<endl;
    cout << "                   |       |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   |       |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void diceArt3() {
    cout << "                    ------- " <<endl;
    cout << "                   |     @ |" <<endl;
    cout << "                   |   @   |" <<endl;
    cout << "                   | @     |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void diceArt4() {
    cout << "                    ------- " <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   |       |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
    
}
void diceArt5() {
    cout << "                    ------- " <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   |   @   |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
void diceArt6() {
    cout << "                    ------- " <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                   | @   @ |" <<endl;
    cout << "                    ------- " <<endl << endl;
    cout << string( 20, '\n' );
}
//just like "rolling" delay
void holding() {
    time_t t1, t2;
    cout << endl << "holding." << flush;
    for (int x = 0; x < 3; x++) {
        t1 = time(0);
        do {
            t2 = time(0);
        } while (difftime (t2, t1) < 1);
        cout << "." << flush;
    }
}
bool checkWin(const int pointCap, int potentialScore, int overallScore, bool& win, float wager) {
    if (potentialScore + overallScore > pointCap) {
        //set display for monetary value
        cout << setprecision(2) << fixed << showpoint;
        cout << "You win! You take the pot and walk with $" << wager * 2 << " dollars." << endl;
        win = true;
        return win;
    }
    else {
        win = false;
        return win;
    }
}
bool checkLoss(const int pointCap, int potentialScore, int overallScore, bool& loss, float wager) {
    if (potentialScore + overallScore > pointCap) {
        //set display for monetary value
        cout << setprecision(2) << fixed << showpoint;
        cout << "The computer beat you!  You lose $" << wager << " dollars." << endl;
        loss = true;
        return loss;
    }
    else {
        loss = false;
        return loss;
    }
}
//scoreBoard, compScoreBoard, clearScreen, compclearScreen and the diceArts all make sure
//screen is new and updated for each turn
void scoreBoard(int potentialScore, int overallScore) {
    cout << string( 32, '\n' );
    cout << "                    |User|" << endl << endl;
    cout << "Turn Total: " << potentialScore << "                         Score: " << overallScore << endl;
    cout << string( 26, '\n' );
}
void compScoreBoard(int potentialScore, int compOverallScore) {
    cout << string( 32, '\n' );
    cout << "                  |Computer|" << endl << endl;
    cout << "Turn Total: " << potentialScore << "                         Score: " << compOverallScore << endl;
    cout << string( 26, '\n' );
}
void clearScreen(int potenitalScore, int diceScore, int overallScore) {
    cout << string( 15, '\n' );
    cout << "                    |User|" << endl << endl;
    cout << "Turn Total: " << potenitalScore + diceScore << "                         Score: " << overallScore << endl;
}
void compClearScreen(int potenitalScore, int diceScore, int compOverallScore){
    cout << string( 15, '\n' );
    cout << "                  |Computer|" << endl << endl;
    cout << "Turn Total: " << potenitalScore + diceScore << "                         Score: " << compOverallScore << endl;
}
float earnings(bool win, float initialBet) {
    float moneyWon;
    if (win) {
        moneyWon = initialBet;
    }
    else {
        moneyWon = (-initialBet);
    }
    return moneyWon;
}
//sorts the 2D array, descending order '6' -> '-' and 'R' -> 'H'
void sortArray(char rollHistory[][COLS], int turns) {
    bool swap;
    int temp;
    do {
        swap = false;
        for (int i = 0; i < turns; i++) {
            if (rollHistory[i][0] < rollHistory[i + 1][0]) {
                temp = rollHistory[i][0];
                rollHistory[i][0] = rollHistory[i + 1][0];
                rollHistory[i + 1][0] = temp;
                swap = true;
            }
        }
    } while (swap);
    do {
        swap = false;
        for (int i = 0; i < turns; i++) {
            if (rollHistory[i][1] < rollHistory[i + 1][1]) {
                temp = rollHistory[i][1];
                rollHistory[i][1] = rollHistory[i + 1][1];
                rollHistory[i + 1][1] = temp;
                swap = true;
            }
        }
    } while (swap);
    cout << "Action         Roll" << endl;
    for (int k = 0; k <= turns; k++) {
        cout << "  " << rollHistory[k][0] << "             " << rollHistory[k][1] << endl;
        
    } 
}

int *fillArray(int throws, int sides) {
    int *d = new int[throws];
    //Loop the number of times to throw the dice
    for(int roll = 0; roll < throws; roll++) {
        *(d + roll) = rand() % sides + 1;
    }
    for(int roll = 0; roll < throws; roll++) {
        cout << *(d + roll) << endl;
    }
    return d;
}
int *sortArray(int *array, int size) {
    //Allocate a sortable array
    int *b = new int[size];
    //Copy the array
    for(int i = 0; i < size; i++){
        b[i] =  array[i];
    }
    //Sort the array
    for(int i = 0;i < size - 1; i++){
        for(int j = i + 1;j < size; j++){
            if(b[i] > b[j]){
                b[i] = b[i]^b[j];
                b[j] = b[i]^b[j];
                b[i] = b[i]^b[j];
            }
        }
    }
    cout << "Sorted Array: " << endl;
    for (int j = 0; j < size; j++) {
        cout << b[j] << " ";
    }
    cout << endl;
    return b;
}
ThrowResults *avgMedMode(int *a,int n) {
    ThrowResults temp;
    //Create a parallel array to sort
    int *b=sortArray(a,n);
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
    temp.maxFreq = maxFreq+1;
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
    temp.nModes = nmodes;
    //Declare and fill the mode array
    int *mode=new int[nmodes];
    nmodes=0;
    count=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq==count)mode[nmodes++]=b[i];
        }else{
            count=0;
        }
    }
    temp.mode = mode;
    //avg
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += b[i];
    }
    temp.avg = static_cast<float>(total)/static_cast<float>(n);
    //median
    if ((n % 2) != 0) {
        temp.median = b[((n - 1) / 2)];
    }
    else if ((n % 2) == 0) {
        temp.median = (static_cast<float>(b[(n/2) - 1]) + static_cast<float>(b[(n / 2)]))/2.0;
    }
    //Clean up and return
    delete []b;
    ThrowResults *pointer = &temp;
    return pointer;
}
void printStat(ThrowResults throwResults) {
    cout << "Average: " << throwResults.avg << endl;
    cout << "Median: " << throwResults.median << endl;
    cout << "Number of Modes: " << throwResults.nModes << endl;
    cout << "Maximum Frequency: " << throwResults.maxFreq << endl;
    for (int i = 0; i < throwResults.nModes; i++){
     cout << "Mode: " << throwResults.mode[i] << " ";
    }
    cout << endl;
}