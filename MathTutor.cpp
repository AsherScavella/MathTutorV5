/*********************************************************************
Program: MathTutor V5
Programer(s): Asher Scavella & Seth Pipim
Date: 11/20/2024
Replit url: https://github.com/AsherScavella/MathTutorV5  &   https://github.com/sepipi01
Description: This is a simple math tutor for younger students. This third version
asks the full name of the user, then randomly generates a math question that can be addition,
subtraction, multiplication, and division. If it breaks then an error message is displayed on
screen informing the user that something went wrong. Then the program displays the equation
for the user and then allows the user to attempt to answer the question, telling them if they
were right or wrong. Then shows the-end-program message. The third version of the math tutor will
repeat the same question depending on how many times the user answers incorrectly. If the user answers
correctly they will level up. If they answer incorrectly they will level down. Each level will
get more difficult by incrementing by 10. The program will display a summary report displaying
the number of questions, number of correct answers, number of incorrect answers, and their
accuracy percentage.
**********************************************************************/
#include <iostream> // this is needed for the cin/cout and left/right alignment
#include <string>   // this is needed for the string
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

void DisplayGameIntro()
{
    // This is a start to the things that make it look nicer to look at
    cout << "**************************************************************";
    cout << endl;

    // this right here is the Ascii art
    cout << "  __  __         _    _       _____        _  " << endl;
    cout << " |  \\/  |  __ _ | |_ | |__   |_   _|_   _ | |_  ___   _ __  "
            << endl;
    cout << R"( | |\/| | / _` || __|| '_ \    | | | | | || __|/ _ \ | '__| )"
            << endl;
    cout << " | |  | || (_| || |_ | | | |   | | | |_| || |_| (_) || |  " << endl;
    cout << R"( |_|  |_| \__,_| \__||_| |_|   |_|  \__,_| \__|\___/ |_|  )"
            << endl;
    cout << endl;

    // here is the welcome and the look good things "*"
    cout << "**************************************************************"
            << endl;
    cout << "*               Welcome to the easy Math Tutor               *"
            << endl;
    cout << "**************************************************************"
            << endl;
    cout << endl;

    // the begging of the facts
    cout << "Fun facts about math:" << endl;
    cout << endl;

    // here are the facts that the user can enjoy
    cout << "  * The Egyptians were the first to use multiplication tables."
            << endl;
    cout << "  * Every odd number has the letter e in it." << endl;
    cout << "  * On dice, opposite sides always add up to the number seven."
            << endl;
    cout << endl;

    // more of the make look good things
    cout << "***************************************************************"
            << endl;
    cout << endl;

};

string GetUserName() {
    string userName;
    // This is where the user can enter there name and then the code welcomes them
    // with their name
    cout << "What is your name? ";
    getline(cin, userName);
    cout << endl;
    cout << "Welcome " << userName << " to the easy math tutor!" << endl;
    cout << endl;
}
int GetNumericValue()
{
    int userAnswer;
    while (!(cin >> userAnswer)) {
        cin.clear(); // clear the cin error flag
        //need to include the limits library to use numeric_limits
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the max input, up to '\n'
        cout << "Invalid input!" << endl;
        cout << "\tPlease enter a number: ";
    }
};

string AskToPlayAgain(string userName) {
    string response;
    while(true) {
        cout << "Would you like to continue playing, " << userName << "? (yes/no): ";
        cin >> response;
        if(response == "yes" || response == "y" || response == "n" || response == "n") {
            break;
        }

        else {
            cout<< "Invalid input"<< endl;}

        return response;
    };

    /* this is the thingy that allows the user to type things in the running code, I
     * was glad I went back a little ways in the zybooks to find an example. testing */
    int main(){
        const int NUM_ATTEMPTS = 3;
        const int LEVEL_RANGE_CHANGE = 10;
        int totalCorrect = 0;
        int totalIncorrect = 0;
        int mathLevel = 1;
        int totalAccuracy = 0;
        string userName = "?"; // This is so that the user can enter there name
        string userInput = "?";
        int userAnswer = 0;
        int leftNum = 0;
        int rightNum = 0;
        enum MathType{MT_ADD, MT_SUB, MT_MUL, MT_DIV}; //Declares mathtype with values of the 4 types (+, -, *, /)
        MathType mathType = MT_ADD;
        int tempNum = 0;
        int levelChange = 10;
        int correctAnswer = 0;
        char mathSymbol = '+';
        vector<vector<int>> questions;

        srand(time(nullptr));

        DisplayGameIntro();

        do {
            leftNum = rand() % (levelChange * mathLevel) + 1;
            rightNum = rand() % (levelChange * mathLevel) + 1;
            mathType = static_cast<MathType>(rand() % 3 + 1);

            vector<vector<int>> GenerateRandomQuestions(int mathLevel, int  currentRange);


            //This line randomly generates the equation for the user to attempt
            switch (mathType) {
                case 0:                 // addition
                    mathSymbol = '+';
                correctAnswer = leftNum + rightNum;
                break;
                case 1:                // subtraction
                    mathSymbol = '-';
                if (leftNum < rightNum) {               //ensure no negatives are given
                    tempNum = leftNum;
                    leftNum = rightNum;
                    rightNum = tempNum;
                }
                correctAnswer = leftNum - rightNum;
                break;
                case 2:                  // multiplication
                    mathSymbol = '*';
                correctAnswer = leftNum * rightNum;
                break;
                case 3:                  // division
                    mathSymbol = '/';
                correctAnswer = leftNum;               // ensure solution is never a fraction
                leftNum *= rightNum;
                break;
                default:               //ensuring system doesn't break when there is an invalid math type
                    cout << "Invalid Math Type is " << mathType << endl;
                cout << "Ending Program." << endl;
                return -1;
            }

            vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAnswer};

            for (int i = 1; i <= NUM_ATTEMPTS; i++) {
                cout << "[Level #" << mathLevel << "] " << "What is " << leftNum << " " << mathSymbol << " " << rightNum << " = ";

                if (userAnswer == correctAnswer) {
                    cout << "Good job! You got it correct!" << endl;
                    if (totalAccuracy < 0) {
                        totalAccuracy = 0;
                    }
                    row.push_back(i);
                    totalAccuracy++;
                    break;
                }
                else {
                    if (i != 3) {
                        cout << "Sorry, that was the wrong answer." << endl;
                        cout << "You have " << NUM_ATTEMPTS - i << " attempts left." << endl;
                    }
                    else {
                        cout << "Sadly, that was also incorrect and you have no more attempts." << endl;
                        if (totalAccuracy > 0) {
                            totalAccuracy = 0;
                        }
                        row.push_back(0);
                        totalAccuracy--;
                        break;
                    }
                }
            }
            questions.push_back(row);
            if (totalAccuracy == 3) {
                mathLevel++;
                totalAccuracy = 0;
                cout << "Level up! You are now on level " << mathLevel << endl;
            }
            else if (totalAccuracy == -3) {
                if (mathLevel > 1) {
                    mathLevel--;
                    totalAccuracy = 0;
                    cout << "Level down! You are now on level " << mathLevel << endl;
                }
                else {
                    cout << "You are at the lowest level. You cannot go any lower!" << endl;
                    totalAccuracy = 0;
                }
            }
            cout << "Would you like to continue? (y/n): ";
            cin >> userInput;
        } while (tolower(userInput == "y") or tolower(userInput == "yes"));

        cout << "*********************************" << endl;
        cout << "         Summary Report          " << endl;
        cout << "*********************************" << endl;
        cout << "Level      Question      Attempts " << endl;
        cout << "----- ------------------ ---------" << endl;

        for(int i = 0; i < questions.size(); i++) {
            mathLevel = questions.at(i).at(0);
            leftNum = questions.at(i).at(1);
            mathSymbol = static_cast<char>(questions.at(i).at(2));
            rightNum = questions.at(i).at(3);
            correctAnswer = questions.at(i).at(4);
            totalAccuracy = questions.at(i).at(5);

            cout << "  " << setw(2) << right << mathLevel << "  "
                << setw(3) << right << leftNum << " "
                << mathSymbol << " "
                << setw(3) << left << rightNum
                << " = "
                << setw(3) << right << correctAnswer;

            if (totalAccuracy != 0) {
                cout << "       "  << totalAccuracy << endl;
                totalCorrect++;
            }
            else {
                cout << "  Incorrect" << endl;
                totalIncorrect++;
            }
        }
        cout << endl;

        int totalQuestions = totalCorrect + totalIncorrect;
        if (totalQuestions > 0)
        {
            cout << "Total Questions: " << setw(5) << right << totalCorrect + totalIncorrect << endl;
            cout << "Total Correct  : " << setw(5) << right << totalCorrect << endl;
            cout << "Total Incorrect: " << setw(5) << right << totalIncorrect << endl;

            double averagePercentage = (static_cast<double>(totalCorrect) / totalQuestions) * 100;
            cout << "Average Correct: " << setw(5) << right << fixed << setprecision(0.0) << averagePercentage << "%" << endl;
        }
        else {
            cout << " There are no questions answered." << endl;
        }

        cout << endl;

        cout << "Keep calm and do math!" << endl;

        return 0;
    }
}
