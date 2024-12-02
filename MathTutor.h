
#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <iostream>
#include <vector>  // for storing the question in a 2D vector
#include <ctime>
#include <string> // for string data types
#include <vector>


using namespace std;

void DisplayGameIntro();
string GetUserName();
int GetNumericValue();
string AskToPlayAgain(string userName, int& currentRange, int& totalCorrect, int& mathLevel, int& totalIncorrect, int allQuestions);
void DisplaySummaryReport(const vector<vector<int>> &allQuestions);
vector<vector<int>> GenerateRandomQuestions(int mathLevel, int  currentRange);
bool GiveThreeAttempts(string userName, vector<vector<int>> &currentQuestions, int totalCorrect, int totalIncorrect);
void CheckForLevelChange(int &totalIncorrect, int &totalCorrect, int &mathLevel, int &currentRange);

#include "MathTutor.cpp"



#endif //MATHTUTOR_H
