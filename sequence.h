#ifndef PROG3_SEQUENCE_H
#define PROG3_SEQUENCE_H

#include <iostream>
#include <stdexcept>

namespace Prog3A
{
    class Sequence
    {
    private:
        static const int SZ = 10; // максимальный размер последовательности
        int cnt; // количество элементов в последовательности
        int sq[SZ]; // массив элементов последоваетельности
    public:
        Sequence() : cnt(0), sq{0} {} // + 1) пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчанию
        explicit Sequence(int el) : cnt(1), sq{0} { sq[0] = el; } // + 2) создание экземпляров класса с инициализацией единственным элементом последовательности
        Sequence(int sz, const int *a); // + 3) создание экземпляров класса с инициализацией размером и значениями элементов последовательности
        friend std::istream& operator>> (std::istream &in, Sequence &ptr); // + 4) ввод экземпляров класса из входного потока
        friend std::ostream& operator<< (std::ostream &out, const Sequence &ptr); // + 5) вывод значений экземпляров класса в выходной поток
        void add(Sequence ptr1, Sequence ptr2); // + 6) объединение двух последовательностей в одну; в результате формируется новый вектор с сохранением исходных
        Sequence sub(int opt); // + 7) выделение первой упорядоченной по возрастанию или по убыванию последовательности длиной не менее трёх элементов
        int push(int el); // + 8) выполнение операции включения в последовательность нового элемента
        [[nodiscard]] int group() const; // + 9) определение количества групп в последовательности
        [[nodiscard]] int freq(int el) const; // + 10) определение частоты появления некоторого элемента в последовательности
    };

}

#endif //PROG3_SEQUENCE_H