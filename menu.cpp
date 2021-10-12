#include "menu.h"

// 1.
void emptyConstructor(Prog3A::Sequence *ptr)
{
    Prog3A::Sequence tmp;
    *ptr = tmp;
}

// 2.
void firstConstructor(Prog3A::Sequence *ptr)
{
    int el;
    std::cout << "Enter element of the sequence: ->";
    getNum(el);
    Prog3A::Sequence tmp(el);
    *ptr = tmp;
}

// 3.
void secondConstructor(Prog3A::Sequence *ptr)
{
    int sz;
    std::cout << "Enter the number of elements in the sequence: ->";
    getNum(sz);
    int val[100] = {0};
    std::cout << "Enter the elements of the sequence: ->";
    for (int i = 0; i < sz; i++)
        std::cin >> val[i];
    try
    {
        Prog3A::Sequence tmp(sz, val);
        *ptr = tmp;
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
}

// 4.
void inputSequence(Prog3A::Sequence *ptr)
{
    try
    {
            std::cin >> *ptr;
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
}

// 5.
void outputSequence(Prog3A::Sequence ptr)
{
    try
    {
        std::cout << ptr;
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
}

// 6.
void combiningTwoSequence(Prog3A::Sequence *ptr)
{
    Prog3A::Sequence a, b;
    inputSequence(&a);
    inputSequence(&b);
    try
    {
        ptr->add(a, b);
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
}

// 7.
void findingSubsequence(Prog3A::Sequence ptr)
{
    int opt;
    Prog3A::Sequence ans;
    std::cout << "1. Find an increasing subsequence" << std::endl;
    std::cout << "2. Find a decreasing subsequence" << std::endl;
    do {
        std::cout << "Select an option: ->" << std::endl;
        getNum(opt);
    } while (opt != 1 && opt != 2);
    try
    {
        ans = ptr.sub(opt);
        std::cout << ans;
    }
    catch(std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
}

// 8.
void pushElement(Prog3A::Sequence *ptr)
{
    int el;
    std::cout << "Enter element of the sequence: ->";
    getNum(el);
    try
    {
        ptr->push(el);
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
}

// 9.
void determiningGroups(Prog3A::Sequence ptr)
{
    std::cout << "Number of groups in the sequence: ->" << ptr.group() << std::endl;
}

// 10.
void determiningFrequency(Prog3A::Sequence ptr)
{
    int el;
    std::cout << "Enter element of the sequence: ->";
    getNum(el);
    std::cout << "The number of sequence n = " << el << " is repeated " << ptr.freq(el) << " times" << std::endl;
}
