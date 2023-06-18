//4) В текстовом файле дана последовательность чисел.Написать рекурсивную
//подпрограмму, которая вычисляет среднее арифметическое элементов
//непустого однонаправленного списка.Используя эту подпрограмму,
//вычислить среднее арифметическое чисел заданной последовательности.

#include<iostream>
#include<fstream>

using namespace std;

struct node
{
	node* next;
	int elem;
};

void recurse(node* head, int& sum, int& count)
{
	if (head->next != NULL)
	{
		node* p = head->next;
		sum += p->elem;
		count++;
		recurse(p, sum, count);
	}
}

int main()
{
	ifstream fin("input.txt");
	int sum = 0, count = 0;
	node* list = new node; list->next = NULL; node* head; head = list;
	while (!fin.eof())
	{
		list->next = new node;
		list = list->next;
		fin >> list->elem;
	}
	list->next = NULL;
	list = head;
	recurse(head, sum, count);
	cout << sum / count << endl;
	return 0;
}
