#include "digitOperations.h"
#include <iostream>
#include <ctime>

bool isFourDigit(int number)
{
    bool result = number < 1000 || number > 9999;

    if (result)
    {
        std::cout << "❌ Please enter a 4-digit number: ";
    }
    return result;
}
void splitNumberIntoDigits(int number, unsigned short& digit1, unsigned short& digit2, unsigned short& digit3, unsigned short& digit4)
{
    digit1 = number / 1000;
    digit2 = (number / 100) % 10;
    digit3 = (number / 10) % 10;
    digit4 = (number % 10);
}

unsigned short generateDigit(unsigned short min, unsigned short max)
{
    srand(time(nullptr));

    return std::rand() % (max+1-min) + min;
}

void generateUniqueDigits(unsigned short& digit1, unsigned short& digit2, unsigned short& digit3, unsigned short& digit4)
{
    digit1 = generateDigit(1,9);

    do
    {
        digit2 = generateDigit(0,9);
    }
    while (digit2 == digit1);

    do
    {
        digit3 = generateDigit(0,9);
    }
    while (digit3 == digit1 || digit3 == digit2);

    do
    {
        digit4 = generateDigit(0,9);
    }
    while (digit4 == digit1 || digit4 == digit2 || digit4 == digit3);
}