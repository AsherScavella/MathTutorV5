// Intro
#include <iostream>
#include <vector>
#include "MathTutor.h"
#include <string>
#include <ctime>
#include <limits>
using namespace std;

int main()
{

    int totalCorrect =0;
    int totalIncorrect =0;
    int mathLevel = 1;
    int currentRange = 10;
    vector<vector<int>> questions;
    string userName = "?";
    string userInput = "?";
    bool playAgain = false;
    srand(time(NULL));
    DisplayGameIntro();
    userName = GetUserName();

    while (playAgain)
    {
        vector<int> question = GenerateRandomQuestion(mathLevel, currentRange);
        GiveThreeAttempts(userName, question, totalIncorrect, totalCorrect);
        questions.push_back(question);

        CheckForLevelChange(totalIncorrect, totalCorrect, mathLevel, currentRange);
        userInput = AskToPlayAgain(userName);
        playAgain = (userInput == "y"|| userInput == "yes");
    }
    DisplaySummaryReport(questions);

    cout<< "Check back nex time" << endl;
    return 0;

}
