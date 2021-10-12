#include "menu.h"

int main() {
    int command;
    Prog3A::Sequence tmp;

    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Empty constructor" << std::endl;
    std::cout << "2. Creating a sequence with a single element" << std::endl;
    std::cout << "3. Creating a sequence with multiple elements" << std::endl;
    std::cout << "4. Input a sequence" << std::endl;
    std::cout << "5. Output a sequence" << std::endl;
    std::cout << "6. Combining two sequences" << std::endl;
    std::cout << "7. Subsequence extraction" << std::endl;
    std::cout << "8. Pushing the new element" << std::endl;
    std::cout << "9. Determining the number of groups" << std::endl;
    std::cout << "10. Determining the frequency of occurrence" << std::endl;
    do {
        std::cout << "Enter the command: ->";
        getNum(command);
        switch(command)
        {
            case 0:
                std::cout << "EXIT!" << std::endl;
                break;
            case 1:
                emptyConstructor(&tmp);
                break;
            case 2:
                firstConstructor(&tmp);
                break;
            case 3:
                secondConstructor(&tmp);
                break;
            case 4:
                inputSequence(&tmp);
                break;
            case 5:
                outputSequence(tmp);
                break;
            case 6:
                combiningTwoSequence(&tmp);
                break;
            case 7:
                findingSubsequence(tmp);
                break;
            case 8:
                pushElement(&tmp);
                break;
            case 9:
                determiningGroups(tmp);
                break;
            case 10:
                determiningFrequency(tmp);
                break;
            default:
                std::cout << "ERROR! There is no such command." << std::endl;
        }
    } while (command != 0);

    return 0;
}
