//12) В файле содержатся элементы упорядоченной по убыванию ключа таблицы
//след.вида: Шифр студента(10 символов), ФИО студента(25 символов), Средний
//балл(вещественное).Ключ элемента – шифр студента.Ключ таблицы
//однозначно определяет её элемент.Количество элементов не превышает 100.
//Используя бинарный поиск, включить в таблицу ещё один элемент.

#include<iostream>
#include<fstream>
#include<cstring>
#define N 100

using namespace std;

struct el
{
    int shifr;
    char name[35];
    float mark;
};

struct table
{
    el elem[N];
    int n;
};

void show(table list)
{
    for (int i = 0; i < list.n; i++)
    {
        cout << endl;
        cout << i + 1 << " " << list.elem[i].shifr << " " << list.elem[i].name << " " << list.elem[i].mark;
    }
}

void InsertTable(table* G, el x) {
    int i = G->n - 1;
    while (i >= 0 && G->elem[i].shifr < x.shifr) {
        G->elem[i + 1] = G->elem[i];
        i--;
    }
    G->elem[i + 1] = x;
    G->n++;
}

int main()
{

    setlocale(LC_ALL, "Rus");
    ifstream text("spisok.txt");
    table list;
    el dummy;
    list.n =0 ;
 
    while (list.n < N && text >> list.elem[list.n].shifr >> list.elem[list.n].name >> list.elem[list.n].mark)
    {
        list.n++;
    }
    text.close();
    show(list);

    cout << "\nВведите данные нового элемента:\n";
    cin >> dummy.shifr >> dummy.name >> dummy.mark;

    InsertTable(&list, dummy);

    show(list);

    return 0;
}