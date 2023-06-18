//5) В текстовом файле дана последовательность чисел.Написать рекурсивную
//подпрограмму, которая находит максимальный элемент непустого
//однонаправленного списка.Используя эту подпрограмму, удалить из заданной
//последовательности все элементы со значениями меньше максимального.

#include <iostream>
#include <fstream>
using namespace std;
ifstream file;
ofstream fileo;

struct list
{
	int elem;
	list* next;
};

void findMax(list* s1, int& max)
{
	if (s1 != NULL)
	{
		if (max < s1->elem)
		{
			max = s1->elem;
		}
		findMax(s1->next, max);
	}
	else return;
}

void del(list* s1, int max)
{
	list* r;
	while (s1->next)
	{
		if (s1->next->elem != max)
		{
			r = s1->next;
			s1->next = r->next;
			delete r;
		}
		else s1 = s1->next;
	}
}

void print(list* s1) 
{
	fileo.open("test.txt");
	while (s1->next)
	{
		s1 = s1->next;
		fileo << s1->elem << " ";
	}
	fileo.close();
}

int main()
{
	list* s1 = new list; s1->next = NULL; list* head; head = s1;
	file.open("test.txt");
	while (!file.eof())
	{
		s1->next = new list;
		s1 = s1->next;
		file >> s1->elem;
	}
	s1->next = NULL;
	s1 = head;
	int max = 0;
	findMax(s1, max);
	cout << max;
	del(s1, max);
	print(s1);
}

