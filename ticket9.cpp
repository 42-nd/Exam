#include <iostream>
#include <fstream>
using namespace std;

struct list {
    int elem;
    list* next;
};

int minelem(list* head) {
    int min = 2147483647;
    list *p = head;
    while (p->next != head) {
        if (p->elem < min) {
            min = p->elem;
        }
        p = p->next;
    }
    if (p->elem < min) {
        min = p->elem;
    }
    return min;
}

void moveToBack(list* head, int val) {

    if (head == nullptr) {
        return;
    }
    list* last = head;
    while (last->next != head) {
        last = last->next;
    }
    list* current = head;
    while (current->next != last) {
        if (current->next->elem == val) {
            list* temp = current->next;
            current->next = current->next->next;
            temp->next = head;
            last->next = temp;
            return;
        }
        current = current->next;
        
    }
   
}
int main()
{
    ifstream spisok;
    list* p, * head;
    int l = 1;
    p = head = new list;
    
    spisok.open("spisok.txt");
    if (spisok) {
        if ((spisok.peek() != EOF)) {
            spisok >> p->elem;
            p->next = head;
            while (!spisok.eof()) {
                l += 1;
                p->next = new list;
                p = p->next;
                spisok >> p->elem;
                p->next = head;
            }
            int min = minelem(head);
            p = head;
            for (int i=0; i < l; i++) {
                if (p->elem == min) {
                    moveToBack(head, min);
                }
                p = p->next;

            }
            //вывод списка
            p = head;
            while (p->next != head) {
                cout << p->elem;
                p = p->next;
            }
            cout << p->elem;
        }
    }
    return 0;
}
