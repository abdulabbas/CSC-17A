/* 
 * File:   Score.h
 * Author: Abdul-Hakim
 * Created on October 16, 2015, 10:53 AM
 */

#ifndef SCORE_H
#define	SCORE_H
class VirtualScore {
    virtual void scoreBoard(int potentialScore, int overAllScore) = 0;
    virtual void compScoreBoard(int potenitalScore, int compOverallScore) = 0;
    virtual void clearScreen(int potenitalScore, int diceScore, int overAllScore) = 0;
    virtual void compClearScreen(int potentialScore, int diceScore, int compOverallScore) = 0;
};
class Score : public VirtualScore {
private:
    int potentialScore;
    int overallScore;
    int diceScore;
    int compOverallScore;
public:
    void scoreBoard(int potentialScore, int overAllScore);
    void compScoreBoard(int potenitalScore, int compOverallScore);
    void clearScreen(int potenitalScore, int diceScore, int overAllScore);
    void compClearScreen(int potentialScore, int diceScore, int compOverallScore);
};

#endif	/* SCORE_H */


