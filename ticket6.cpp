#include <iostream>
#include <fstream>
using namespace std;

struct list {
	char data;
	list* next;
};

void listTransform(list* h, char n){
	int cnt = 0, cnt1 = 0;
	list* p;
	list* s;
	p = h;
	while (p->next != NULL){
		if (p->data == n){
			cnt++;
		}
		p = p->next;
	}
	if (cnt > 1){
		p = h;
		while (p->next != NULL){
			if (p->next->data == n){
				cnt1++;
				if (cnt1 == cnt){
					break;
				}
				s = p->next;
				p->next = p->next->next;
				s->next = NULL;
			}
			else{
				p = p->next;
			}
		}
		p = h->next;
		while (p->next != NULL){
			cout << p->data;
			p = p->next;
		}
	}
	else{
		p = h->next;
		while (p->next != NULL){
			cout << p->data;
			p = p->next;
		}
	}
}

int main(){
	list* p;
	list* head;
	ifstream file;
	file.open("file.txt");
	char sym, elem;
	cout << "select the elem you want to delete: ";
	cin >> elem;
	head = new list;
	head->next = new list;
	p = head->next;
	file >> sym;
	p->data = sym;
	p->next = new list;
	p = p->next;
	while (file >> sym){
		p->data = sym;
		p->next = new list;
		p = p->next;
	}
	p->next = NULL;
	listTransform(head, elem);
}