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

void emptyConstructor(Prog3A::Sequence *ptr);
void firstConstructor(Prog3A::Sequence *ptr);
void secondConstructor(Prog3A::Sequence *ptr);
void inputSequence(Prog3A::Sequence *ptr);
void outputSequence(Prog3A::Sequence ptr);
void combiningTwoSequence(Prog3A::Sequence *ptr);
void findingSubsequence(Prog3A::Sequence ptr);
void pushElement(Prog3A::Sequence *ptr);
void determiningGroups(Prog3A::Sequence ptr);
void determiningFrequency(Prog3A::Sequence ptr);

#endif //PROG3_MENU_H
