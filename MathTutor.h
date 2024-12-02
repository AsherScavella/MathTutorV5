
#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <iostream>
#include <vector>  // for storing the question in a 2D vector
#include <string> // for string data types

using namespace std;

void DisplayGameIntro();
string GetUserName();
int GetNumericValue();
string AskToPlayAgain(string userName);
void DisplaySummaryReport(const vector<vector<int>> &allQuestions);
vector<int> GenerateRandomQuestion(int mathLevel);
bool GiveThreeAttempts(string userName, vector<int> &currentQuestions);
void CheckForLevelChange(int &totalIncorrect, int &totalCorrect, int &mathLevel, int &currentRange);

#endif MATHTUTOR_H
