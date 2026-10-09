#include "consoleMessages.h"
#include <iostream>

using std::cout, std::endl ;

void welcomeMessage()
{
    cout << "===============================================" << endl;
    cout << "    🐂 WELCOME TO BULLS AND COWS! 🐄" << endl;
    cout << "===============================================" << endl;
    cout << endl;
    cout << "🎯 I've thought of a 4-digit number with no repeated digits." << endl;
    cout << "🤔 Try to guess it!" << endl;
    cout << endl;
    cout << "📋 RULES:" << endl;
    cout << "🐂 Bulls = correct digits in correct positions" << endl;
    cout << "🐄 Cows = correct digits in wrong positions" << endl;
    cout << endl;
    cout << "🎮 Enter your guess (4 digits): ";
}

void congratulationMessage(int secretNumber, int attempts)
{
    cout << endl;
    cout << "🎉🎉🎉 CONGRATULATIONS! 🎉🎉🎉" << endl;
    cout << "🏆 You guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
    cout << "🎊 Well done!" << endl;
}