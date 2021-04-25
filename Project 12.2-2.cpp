// Lab_12_2.cpp
// < Кузів Назар >
// Лабораторна робота № 12.2
// Опрацювання лінійного однонаправленого списку
// Варіант 6


#include <iostream>
#include <Windows.h>

using namespace std;

struct Elem
{
    Elem* link;
    int info;
};

void Create(Elem*& first, Elem*& last, int value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;

    if (last != NULL)
        last->link = tmp;

    last = tmp;

    if (first == NULL)
        first = tmp;
}

void Print(Elem* first)
{
    if (first != NULL)
    {
        cout << first->info << " ";
        Print(first->link);
    }
    else
        return;
}
void Increase(Elem* first, int N)
{
    if (first != NULL)
    {
        first->info += N;
        Increase(first->link,N);
    }
    else
        return;
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;


    Elem* first = NULL,
        * last = NULL;

    for (int i = 1; i <= 10; i++)
        Create(first, last, i);

    cout << endl;
    Print(first);
    cout << endl<<endl;

    cout << "Введіть на скільки потрібно збільшити значення кожного елемента списку: ";
    cin >> N;

    Increase(first, N);

    cout << endl;
    Print(first);

    return 0;
}
