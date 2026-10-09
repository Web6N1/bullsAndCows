#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "digitOperations.h"
#include "consoleMessages.h"

void processNumberInput(int guess, bool& isInputLegal, unsigned short& digit1, unsigned short& digit2, unsigned short& digit3, unsigned short& digit4);
void countBullsAndCows(int& bulls, int& cows, int secretNumber, int guess);

int main()
{
    SetConsoleOutputCP(CP_UTF8);   // консоль будет декодировать вывод как UTF-8
    SetConsoleCP(CP_UTF8);         // и ввод тоже, на всякий случай

    unsigned short digit1, digit2, digit3, digit4;
    generateUniqueDigits(digit1, digit2, digit3, digit4);

    int secretNumber = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;

    welcomeMessage();

    int attempts = 0;
    int guess{0};

    while (std::cin >> guess)
    {
        attempts++;
        unsigned short guessDigit1{0}, guessDigit2{0}, guessDigit3{0}, guessDigit4{0};
        bool isInputLegal{true};

        processNumberInput(guess, isInputLegal, guessDigit1, guessDigit2, guessDigit3, guessDigit4);
        if (isInputLegal) continue;

        int bulls = 0;
        int cows = 0;

        countBullsAndCows(bulls, cows, secretNumber, guess);

        std::cout << "🎯 Result: 🐂 Bulls: " << bulls << ", 🐄 Cows: " << cows << std::endl;

        if (bulls == 4)
        {
            congratulationMessage(secretNumber, attempts);
            break;
        }

        std::cout << "🔄 Try again: ";
    }

    return 0;
}


void processNumberInput(int guess, bool& isInputLegal, unsigned short& digit1, unsigned short& digit2, unsigned short& digit3, unsigned short& digit4)
{
    isInputLegal = isFourDigit(guess);

    splitNumberIntoDigits(guess, digit1, digit2, digit3, digit4);

    bool hasRepeatedDigits = (digit1 == digit2 || digit1 == digit3 || digit1 == digit4 || digit2 == digit3 || digit2 == digit4 || digit3 == digit4);

    if (hasRepeatedDigits)
    {
        std::cout << "🔄 Please enter a number with no repeated digits: ";
        isInputLegal = false;
    }
}

void countBullsAndCows(int& bulls, int& cows, int secretNumber, int guess)
{
    unsigned short secretDigit1, secretDigit2, secretDigit3, secretDigit4;
    unsigned short guessDigit1, guessDigit2, guessDigit3, guessDigit4;

    splitNumberIntoDigits(secretNumber, secretDigit1, secretDigit2, secretDigit3, secretDigit4);
    splitNumberIntoDigits(guess, guessDigit1, guessDigit2, guessDigit3, guessDigit4);

    if (secretDigit1 == guessDigit1) bulls++;
    if (secretDigit2 == guessDigit2) bulls++;
    if (secretDigit3 == guessDigit3) bulls++;
    if (secretDigit4 == guessDigit4) bulls++;

    if (secretDigit1 == guessDigit2 || secretDigit1 == guessDigit3 || secretDigit1 == guessDigit4) cows++;
    if (secretDigit2 == guessDigit1 || secretDigit2 == guessDigit3 || secretDigit2 == guessDigit4) cows++;
    if (secretDigit3 == guessDigit1 || secretDigit3 == guessDigit2 || secretDigit3 == guessDigit4) cows++;
    if (secretDigit4 == guessDigit1 || secretDigit4 == guessDigit2 || secretDigit4 == guessDigit3) cows++;
}
