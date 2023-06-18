// БИЛЕТ 2
#include <iostream>
#include <fstream>
using namespace std;

struct list
{
	char data;
	list *next;
};

void cheklists(list *s1, list *s2, list *h1, list *h2, int n)
{
	int i = 0;
	while (s1->next != h1 && s2->next != h2)
	{
		if (s1->next->data == s2->next->data)
		{
			s1 = s1->next;
			s2 = s2->next;
			i++;
		}
		else
		{
			s2 = s2->next;
			i = 0;
		}
	}
	if (i == n)
	{
		cout << "s1 is included in s2";
	}
	if (i != n)
	{
		s1 = h1;
		s2 = h2;
		while (s2->next != h2)
		{
			s2 = s2->next;
		}
		while (s1->next != h1)
		{
			s2->next = new list;
			s2 = s2->next;
			s2->data = s1->next->data;
			s1 = s1->next;
		}
		s2->next = h2;
		s2 = h2;
		while (s2->next != h2)
		{
			cout << s2->next->data;
			s2 = s2->next;
		}
	}
	s2 = h2;
}

int main()
{
	int i = 0, n;
	char *arr = new char[50];
	ifstream fin("file.txt");
	fin >> arr;
	list *s1 = new list;
	s1->next = NULL;
	list *head1 = s1;
	list *s2 = new list;
	s2->next = NULL;
	list *head2 = s2;
	while (arr[i])
	{
		s1->next = new list;
		s1 = s1->next;
		s1->data = arr[i];
		i++;
	}
	n = i;
	s1->next = head1;
	s1 = head1;
	i = 0;
	fin >> arr;
	while (arr[i])
	{
		s2->next = new list;
		s2 = s2->next;
		s2->data = arr[i];
		i++;
	}
	s2->next = head2;
	s2 = head2;
	cheklists(s1, s2, head1, head2, n);
}
