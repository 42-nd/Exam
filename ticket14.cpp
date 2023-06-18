#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;

const int N = 10;

struct queue
{
    int end;
    int data[N]; // приоритет - значение элемента
};

int main()
{
    setlocale(LC_ALL, "Rus");
    queue* Q = new queue;
    Q->end = -1;

    int value;
    fin.open("spisok.txt");
    if ((fin.peek() != EOF)) {
        while (Q->end < N - 1 and !fin.eof())
        {
            fin >> value;
            if (value <= 0) {
                cout << "Значение: " << value << " не учитывается - не удовлетворяет условиям задачи"<< endl;
                break;
            }

            if (Q->end < 0)
            {
                int i = Q->end + 1;
                Q->data[i] = value;
                Q->end++;

            }
            else
            {
                int j = 0;
                while (j <= Q->end and Q->data[j] <= value) j++;
                int k = Q->end;
                while (k >= j)
                {
                    Q->data[k + 1] = Q->data[k];
                    k--;
                }
                Q->data[j] = value;
                Q->end++;
            }
        }
        fin.close();

        if (Q->end < 0) cout << "Queue is empty";
        else
        {
            for (int i = 0; i <= Q->end; i++)
            {
                cout << Q->data[i] << " ";
            }
        }
    }
}