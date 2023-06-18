//7) В текстовом файле дана последовательность чисел.Написать рекурсивную
//подпрограмму, которая печатает в обратном порядке элементы непустого
//однонаправленного списка.Используя эту подпрограмму, напечатать
//заданную последовательность в обратном порядке.

#include<iostream>
#include<fstream>

using namespace std;

struct node
{
	node* next;
	int elem;
};

void recurse(node* list, node* head, int sum, int sumconst)
{
	if (sum > 1)
	{
		recurse(list->next, head, sum -= 1, sumconst);
	}
	else if (sumconst > 0)
	{
		cout << list->elem << " ";
		recurse(head->next, head, sumconst, sumconst -= 1);
	}
	else return;
}

int main()
{
	ifstream fin("input.txt");
	int sum = 0;
	node* list, * head;
	list = new node;
	list->next = NULL;
	list->elem = NULL;
	head = list;
	while (!fin.eof())
	{
		list->next = new node;
		list = list->next;
		fin >> list->elem;
		sum++;
	}
	list->next = NULL;
	list = head;
	int sumconst = sum;
	recurse(list->next, head, sum, sumconst);
}
