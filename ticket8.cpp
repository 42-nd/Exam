//8) В текстовом файле дана последовательность чисел.Написать подпрограмму
//поиска k–го элемента однонаправленного циклического списка, считая, что k
//– номер элемент, а нумерация начинается с 1 от 1 - го элемента списка.Учесть
//возможную некорректность задания k.Используя эту подпрограмму,
//вычислить разность элементов заданной последовательности с номерами x и y.

#include <iostream>
#include <fstream>

using namespace std;

struct list
{
    int value;
    list* next;
};

int get_len_list(list* head)
{
    int k = 0;
    list* p;
    p = head;
    while (p->next != head)
    {
        k++;
        p = p->next;
    }
    return k;
}

int get_elem(list* head, int index)
{
    int k = 0;
    list* p;
    p = head;
    if (index > get_len_list(head) or index == 0 or index < 0) {
        cout << "your data uncorrectly" << endl;
        return 0;
    }
    else
    {
        while (p->next != head)
        {
            k++;

            if (k == index)
            {
                return p->value;
                break;
            }
            p = p->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    list* p;
    list* head;
    ifstream fin;
    fin.open("input.txt");
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        int n;
        int x, y, result;
        cout << "Введите x: ";
        cin >> x;
        cout << "Введите y: ";
        cin >> y;
        head = new list;
        fin >> n;
        head->value = n;
        head->next = new list;
        p = head->next;
        while (fin >> n)
        {
            p->value = n;
            p->next = new list;
            p = p->next;
        }
        p->next = head;
        result = get_elem(head, x) - get_elem(head, y);
        cout << result << endl;
    }
}


