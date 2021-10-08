#include "sequence.h"

namespace Prog3 {
    // 3. Создание экземпляров класса с инициализацией размером и значениями элементов последовательности.
    Sequence::Sequence(int sz, const int* a) : sq{0}
    {
        if (sz < 0 || sz > SZ)
            throw std::length_error("Illegal size for sequence!");
        else
        {
            cnt = sz;
            for (int i = 0; i < cnt; i++)
                sq[i] = a[i];
        }
    }

    // 4. Ввод экземпляров класса из входного потока.
    std::istream& operator>> (std::istream &in, Sequence &ptr)
    {
        int sz, el;
        std::cout << "Enter the number of elements in sequence: ->";
        in >> sz;
        if (sz < 0 || sz > Prog3::Sequence::SZ)
            throw std::length_error("Illegal size for sequence!");
        else
        {
            std::cout << "Enter the elements of the sequence: ->";
            for (int i = 0; i < sz; i++)
            {
                in >> el;
                ptr.push(el);
            }
        }
        return in;
    }

    // 5. Вывод значений экземпляров класса в выходной поток.
    std::ostream& operator<< (std::ostream &out, const Sequence &ptr)
    {
        if (ptr.cnt == 0)
            throw std::length_error("Sequence is empty!");
        else
            for (int i = 0; i < ptr.cnt; i++)
                out << ptr.sq[i] << ' ';
        out << std::endl;
        return out;
    }

    // 6. Объединение двух последовательностей в одну; в результате формируется новый вектор с сохранением исходных.
    Sequence & Sequence::add(Sequence a, Sequence b)
    {
        if (a.cnt + b.cnt > SZ)
            throw std::length_error("Sequence is full!");
        else
        {
            for (int i = 0; i < a.cnt; i++)
                sq[i] = a.sq[i];
            cnt += a.cnt;
            for (int i = cnt; i - cnt < b.cnt; i++)
                sq[i] = b.sq[i - cnt];
            cnt += b.cnt;
        }
        return *this;
    }


    // !!! NOT READY !!!
    // 7. Выделение первой упорядоченной по возрастанию или по убыванию последовательности длиной не менее трёх элементов.
    Sequence Sequence::sub(int opt)
    {
        int signal = 0;
        Prog3::Sequence ptr;
        if (cnt < 3)
            throw std::length_error("Sequence too small!");
        for (int i = 0; i < cnt; i++)
        {
            if (signal)
                break;
            ptr.sq[ptr.cnt] = sq[i];
            ptr.cnt++;

            if (opt == 1)
            {
                if (sq[i] > sq[i + 1])
                {
                    if (ptr.cnt < 3)
                        ptr.cnt = 0;
                    else
                        signal = 1;
                }
            }
            else
            {
                if (sq[i] < sq[i + 1])
                {
                    if (ptr.cnt < 3)
                        ptr.cnt = 0;
                    else
                        signal = 1;
                }
            }
        }
        if (ptr.cnt < 3)
            throw std::length_error("Too few elements in subsequence!");
        return ptr;
    }

    // 8. Выполнение операции включения в последовательность нового элемента.
    int Sequence::push(int el)
    {
        if (cnt < SZ)
            sq[cnt++] = el;
        else
            throw std::length_error("Sequence overflow!");
        return cnt;
    }

    // 9. Определение количества групп в последовательности.
    int Sequence::group() const
    {
        int ans = 1, grp[SZ], i, j;
        if (cnt == 0)
            return 0;
        else
        {
            grp[0] = sq[0];
            for (i = 1; i < cnt; i++)
                for (j = 0; j < ans; j++)
                {
                    if (sq[i] == grp[j])
                        break;
                    if (j == ans - 1)
                    {
                        grp[ans++] = sq[i];
                        break;
                    }
                }
        }
        return ans;
    }

    // 10. Определение частоты появления некоторого элемента в последовательности.
    int Sequence::freq(int el) const
    {
        int ans = 0;
        for (int i = 0; i < cnt; i++)
            if (sq[i] == el)
                ans++;
        return ans;
    }
}

