#ifndef PROG3_MENU_H
#define PROG3_MENU_H

#include <iostream>
#include <limits>
#include "sequence.h"

template <class T>
int getNum(T &a)
{
    while (true)
    {
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ERROR! Invalid data! Try again please: ->";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 1;
        }
    }
}

Prog3::Sequence emptyConstructor();
Prog3::Sequence firstConstructor();
Prog3::Sequence secondConstructor();
Prog3::Sequence inputSequence();
void outputSequence(Prog3::Sequence ptr);
Prog3::Sequence combiningTwoSequence();
void findingSubsequence(Prog3::Sequence ptr);
Prog3::Sequence pushElement(Prog3::Sequence ptr);
void determiningGroups(Prog3::Sequence ptr);
void determiningFrequency(Prog3::Sequence ptr);

#endif //PROG3_MENU_H
