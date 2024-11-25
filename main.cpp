
#include "MathTutor.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits> 
#include <vector> 
#include <iomanip> 
using namespace std;

int main() {
    int totalCorrect = 0; 
    int totalIncorrect = 0; 
    int mathLevel = 1; 
    int currentRange = 10; 
    vector<vector<int> > questions; 
    string userName, userInput; 
    bool playAgain = true;


    srand(time(0));


    DisplayGameIntro();
    userName = GetUserName();

    // Shows if the user wants to play again
    while (playAgain) {
        // Generate a random math question
        vector<int> question = GenerateRandomQuestion(mathLevel, currentRange);

        // Allow the user to attempt the question
        GiveThreeAttempts(userName, question, totalCorrect, totalIncorrect);

        // Record the question for the summary
        questions.push_back(question);

        // Check for level changes
        CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel, currentRange);

        // Ask the user if they want to play again
        userInput = AskToPlayAgain(userName);
        playAgain = (userInput == "y" || userInput == "yes");
    }

    // Shows the summary of the questions in a proper display
    DisplaySummaryReport(questions);

    // Displaying to the User that the Program is Finished and that it will be back.
    cout << "Check back soon for the next version. Goodbye!" << endl;
    return 0;
}