#include <iostream>
#include <fstream>

using namespace std;

struct linked_list
{
    linked_list *next;
    int data;
};

void addToLinkedList(linked_list *&list, int dummy)
{
    if (list == nullptr)
    {
        list = new linked_list;
        list->data = dummy;
        list->next = nullptr;
        return;
    }
    addToLinkedList(list->next, dummy);
}
void printLinkedList(linked_list *list)
{
    while (list != nullptr)
    {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}

void checkOrderliness(linked_list *&list, int p_value, int k_index)
{
    bool flag = true;
    linked_list *dummy = list;
    while (list != nullptr)
    {
        if (list->next != nullptr)
        {
            if (list->data <= list->next->data)
            {
                flag = false;
                break;
            }
        }
        list = list->next;
    }
    list = dummy;

    if (flag)
    {
        linked_list *temp = new linked_list;
        temp->data = p_value;
        if (list->data <= p_value)
        {
            temp->next = list;
            list = temp;
            return;
        }
        do
        {
            if (list->next != nullptr && list->next->data > p_value)
            {
                list = list->next;
            }
            else
            {
                temp->next = list->next;
                list->next = temp;
                break;
            }
        } while (list != nullptr);
    }
    else
    {
        if (k_index == 0)
        {
            dummy = list->next;
        }
        else
        {
            while (k_index != 1 && list != nullptr)
            {
                list = list->next;
                k_index -= 1;
            }
            list->next = list->next->next;
        }
    }
    list = dummy;
}

int main()
{
    ifstream input_file("ticket18.txt");
    linked_list *list;
    list = nullptr;
    int dummy;
    while (!input_file.eof())
    {
        input_file >> dummy;
        addToLinkedList(list, dummy);
    }
    printLinkedList(list);
    int p_value = 0, k_index = 0;
    cin >> p_value >> k_index;
    checkOrderliness(list, p_value, k_index);
    printLinkedList(list);
    return 0;
}