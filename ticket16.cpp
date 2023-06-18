#include <iostream>
#include <fstream>

using namespace std;

struct list
{
    char elem;
    list* next;
};

void print(list* head) {
    list* p = head;
    while (p->next != nullptr) {
        cout << p->elem<<" ";
        p = p->next;
    }
    cout << endl;
}

void printRev(list* head)
{
    list* p = head;
    if (p->next->next != nullptr)
    {
        printRev(p->next);
    }
    cout << p->elem<<" ";
}


int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream spisok;
    list* p, * head;
    head = new list;
    head=p = new list;

    char sym;
    spisok.open("spisok.txt");
    if (spisok) {
        if ((spisok.peek() != EOF)) {
            spisok >> sym;
            if (sym != '.') {
                while (sym != '.') {
                    p->elem = sym;
                    p->next = new list;
                    p = p->next;
                    spisok >> sym;
                }
                p->next = nullptr;
            }
            cout << "Исходная последовательность: ";
            print(head);
            cout << "Обратная последовательность: ";
            printRev(head);
        }
    }
    return 0;
}

