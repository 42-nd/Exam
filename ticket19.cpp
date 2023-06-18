#include <iostream>
#include <fstream>
using namespace std;

struct list {
	char data;
	list* prev;
	list* next;
};

void is_symmetrical(list* s, int n) {
	int l = 0;
	list* p = s;
	while (l < n / 2 and s->next->data == p->prev->data) {
		s = s->next;
		p = p->prev;
		l++;
	}
	if (l == n / 2)
		cout << "The sequence is symmetric";
	else
		cout << "The sequence is not symmetric";
}

int main() {
	int n = 0;
	char sym;
	ifstream txt;
	txt.open("file.txt");
	list* s = new list;
	list* h;
	s->next = NULL;
	s->data= NULL;
	h = s;
	do {
		txt >> sym;
		if (sym != '.') {
			s->next = new list;
			s->next->prev = s;
			s = s->next;
			s->data = sym;
			n++;
		}
	} while (sym != '.');
	s->next = h;
	s->next->prev = s;
	s = h;
	is_symmetrical(s, n);
}
