#include "menu.h"

// 1.
Prog3::Sequence emptyConstructor()
{
    Prog3::Sequence ptr;
    return ptr;
}

// 2.
Prog3::Sequence firstConstructor()
{
    int el;
    std::cout << "Enter element of the sequence: ->";
    getNum(el);
    Prog3::Sequence ptr(el);
    return ptr;
}

// 3.
Prog3::Sequence secondConstructor()
{
    int sz;
    std::cout << "Enter the number of elements in the sequence: ->";
    getNum(sz);
    int val[100] = {0};
    std::cout << "Enter the elements of the sequence: ->";
    for (int i = 0; i < sz; i++)
        std::cin >> val[i];
    Prog3::Sequence ptr;
    try
    {
        Prog3::Sequence tmp(sz, val);
        ptr = tmp;
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
    return ptr;
}

// 4.
Prog3::Sequence inputSequence()
{
    Prog3::Sequence ptr;
    try
    {
            std::cin >> ptr;
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
    return ptr;
}

// 5.
void outputSequence(Prog3::Sequence ptr)
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
Prog3::Sequence combiningTwoSequence()
{
    Prog3::Sequence a, b, ptr;
    a = inputSequence();
    b = inputSequence();
    try
    {
        ptr.add(a, b);
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
    return ptr;
}

// 7.
void findingSubsequence(Prog3::Sequence ptr)
{
    int opt;
    Prog3::Sequence ans;
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
Prog3::Sequence pushElement(Prog3::Sequence ptr)
{
    int el;
    std::cout << "Enter element of the sequence: ->";
    getNum(el);
    try
    {
        ptr.push(el);
    }
    catch (std::length_error &lengthError)
    {
        std::cout << lengthError.what() << std::endl;
    }
    return ptr;
}

// 9.
void determiningGroups(Prog3::Sequence ptr)
{
    std::cout << "Number of groups in the sequence: ->" << ptr.group() << std::endl;
}

// 10.
void determiningFrequency(Prog3::Sequence ptr)
{
    int el;
    std::cout << "Enter element of the sequence: ->";
    getNum(el);
    std::cout << "The number of sequence n = " << el << " is repeated " << ptr.freq(el) << " times" << std::endl;
}
