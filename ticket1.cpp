#include <iostream>
#include <fstream>
using namespace std;

struct list
{
    int elem;
    list *next;
    list *prev;
};

list *zamena(list *head)
{

    list *first = head;
    list *last = head->prev;
    first->prev = last->prev;
    last->prev->next = first;
    last->prev = first;
    first->next->prev = last;
    last->next = first->next;
    first->next = last;
    head = last;

    return head;
}
int main()
{

    ifstream spisok;
    list *p, *head;
    p = head = new list;
    spisok.open("ticket1.txt");
    if (spisok)
    {
        if ((spisok.peek() != EOF))
        {
            while (!spisok.eof())
            {
                spisok >> p->elem;
                p->next = new list;
                p->next->prev = p;
                p = p->next;
            }
            p = p->prev;
            p->next = head;
            head->prev = p;

            head = zamena(head);
            p = head;
            cout << p->elem;
            while (p != head->prev)
            {
                p = p->next;
                cout << p->elem;
            }
        }
    }
}
