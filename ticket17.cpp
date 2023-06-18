#include <iostream>
#include <fstream>

using namespace std;

const int N = 50;

struct member
{
    int number;
    float time;
    int mark;
};

struct table
{
    int n;
    member members[N];
};

void displayTable(table *rank_table)
{
    for (int i = 0; i < rank_table->n; ++i)
    {
        cout << "Member " << i + 1 << ": "
             << "Number: " << rank_table->members[i].number << ", "
             << "Time: " << rank_table->members[i].time << ", "
             << "Mark: " << rank_table->members[i].mark << endl;
    }
}

int main()
{
    ifstream input_file("ticket17.txt");

    table *rank_table = new table;
    int i = 0;

    while (!input_file.eof() && i < 50)
    {
        input_file >> rank_table->members[i].number;
        input_file >> rank_table->members[i].time;
        input_file >> rank_table->members[i].mark;
        i++;
    }
    rank_table->n = i;
    displayTable(rank_table);
    cout << "----------" << endl;
    // Сортировка по времени приготовления в порядке возрастания
    for (int i = 0; i < rank_table->n - 1; ++i)
    {
        for (int j = 0; j < rank_table->n - i - 1; ++j)
        {
            if (rank_table->members[j].time > rank_table->members[j + 1].time)
            {
                swap(rank_table->members[j], rank_table->members[j + 1]);
            }
        }
    }
    displayTable(rank_table);
    cout << "----------" << endl;
    // Сортировка по оценке жюри в порядке убывания
    for (int i = 0; i < rank_table->n - 1; ++i)
    {
        for (int j = 0; j < rank_table->n - i - 1; ++j)
        {
            if (rank_table->members[j].mark < rank_table->members[j + 1].mark)
            {
                swap(rank_table->members[j], rank_table->members[j + 1]);
            }
        }
    }
    displayTable(rank_table);
    cout << "----------" << endl;
    for (int i = 0; i < min(3, rank_table->n); ++i)
    {
        cout << rank_table->members[i].number << " ";
    }

    return 0;
}
