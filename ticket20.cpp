#include <iostream>
#include <fstream>

using namespace std;

struct dat
{
    int age;
    string surname;
};

struct linked_list
{
    linked_list *next;
    dat info;
};

void addToLinkedList(linked_list *&list, dat dummy)
{
    if (list == nullptr)
    {
        list = new linked_list;
        list->info = dummy;
        list->next = nullptr;
        return;
    }
    addToLinkedList(list->next, dummy);
}
void printLinkedList(linked_list *list)
{
    while (list != nullptr)
    {
        cout << list->info.surname << " " << list->info.age << endl;
        list = list->next;
    }
}
int countWaitingTime(linked_list *list, string surname1, string surname2)
{
    int time = 0;
    int flag = false;
    while (list != nullptr)
    {
        if (list->info.surname == surname1)
        {
            return time;
        }
        if (flag)
        {
            time += 20;
        }
        else if (list->info.surname == surname2)
        {
            flag = true;
            time += 20;
        }
        list = list->next;
    }
    return -1;
}
int main()
{
    ifstream input_file("ticket20.txt");
    linked_list *list;
    list = nullptr;
    dat dummy;
    while (!input_file.eof())
    {
        input_file >> dummy.surname;
        input_file >> dummy.age;
        addToLinkedList(list, dummy);
        }
    printLinkedList(list);
    cout << "----------" << endl;
    string surname1;
    string surname2;
    cin >> surname1 >> surname2;

    cout << countWaitingTime(list, surname1, surname2);
    return 0;
}