#include <iostream>
#include <fstream>
using namespace std;

struct list {
    char elem;
    list* next;
};

void printsp(list* head) {
    list* p = head->next;
    while (p->next != nullptr) {
        cout << p->elem<<" ";
        p = p->next;
    }
}
void delElem(list* head, char sym) {
    list* p = head;
    while (p->next != nullptr) {
        if (p->next->elem == sym) {
            list* temp = p->next;
            p->next = temp->next;
            delete temp;

        }
        p = p->next;
    }
}
int main()
{
    ifstream spisok;
    list* p1, * head1, *p2,*head2;
    head1 = new list;
    head2 = new list;
    head1->next = new list;
    head2->next = new list;
    p1 = head1->next;
    p2 = head2->next;
    char sym;
    spisok.open("spisok.txt");
    if (spisok) {
        if ((spisok.peek() != EOF)) {
            spisok >> sym;
            while (sym != ',') {
                p1->elem = sym;
                p1->next = new list;
                p1 = p1->next;
                spisok >> sym;
            }
       
            p1->next = nullptr;

            spisok >> sym;
            while (!spisok.eof()) {
                p2->elem = sym;
                p2->next = new list;
                p2 = p2->next;
                spisok >> sym;
            }

            p2->next = nullptr;
            p2 = head2->next;
            while (p2->next != nullptr) {
                delElem(head1, p2->elem);
                p2 = p2->next;
            }
            printsp(head1);
        }
        

        }
    return 0;
}

