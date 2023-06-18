//3) В текстовом файле дана последовательность чисел.Написать подпрограмму,
//которая находит среднее арифметическое неотрицательных элементов
//двунаправленного списка.Используя эту подпрограмму, вычислить среднее
//арифметическое заданной последовательности.

#include <iostream>
#include <fstream>
using namespace std;

struct List
{
    int number;
    List* next;
    List* prev;
};

void printList(List* head)
{
    List* p;
    for (p = head->next; p != NULL; p = p->next)
    {
        cout << p->number << " ";
    }
}

void srd(List* head)
{
    List* p;
    int sum = 0, count = 0, srdn = 0;
    for (p = head->next; p != NULL; p = p->next)
    {
        if ((p->number) >= 0) {
            sum += p->number;
            ++count;
        }
    }
    srdn = (sum / count);
    cout << srdn;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream fin;
    List* head;
    List* p;
    List* t;
    int number;
    head = new List;
    t = p = head;
    fin.open("input.txt");
    while (!fin.eof())
    {
        fin >> number;
        p = new List;
        t->next = p;
        p->number = number;
        p->prev = t;
        p->next = NULL;
        t = t->next;
    }
    fin.close();
    cout << "Исходный список: " << endl;
    printList(head);
    cout << "\nСреднее арифметическое: " << endl;
    srd(head);
    return 0;
}