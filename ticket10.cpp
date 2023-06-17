#include <iostream>
#include <fstream>
using namespace std;

struct list {
    float elem;
    list* next;
};

float sumel(list* head) {
    
    list* p = head;
    while (p->next->next!= nullptr) {
        p = p->next;

    }
    return p->next->elem + p->elem;
}
int main()
{
    ifstream spisok;
    list* p, * head;
    float Flag = false;
    p = head = new list;

    spisok.open("spisok.txt");
    if (spisok) {
        if ((spisok.peek() != EOF)) {
            spisok >> p->elem;
            while (!spisok.eof()) {
                p->next = new list;
                p = p->next;
                spisok >> p->elem;
                Flag = true;
            }
            p->next = nullptr;
            if (Flag == true) {
                cout << sumel(head);
            }
            else {
                cout << "Not elements for sum";
            }

        }
    }
    return 0;
}