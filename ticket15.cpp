#include<iostream>
#include<fstream>
#define N 100

using namespace std;

struct elem
{
    int number;
    float start;
    float finish;
};

struct table
{
    int n = 0;
    elem el[N];
};

void add(table& T, elem dummy)
{
    int i = T.n - 1;
    float time = dummy.finish - dummy.start;
    while (i >= 0 && time > (T.el[i].finish - T.el[i].start))
    {
        T.el[i + 1] = T.el[i];
        i--;
    }
    T.el[i + 1] = dummy;
    T.n++;
}

int main()
{
    ifstream fin("input.txt");
    table T;
    T.n = 0;
    elem dummy;
    while (!fin.eof())
    {
        fin >> dummy.number;
        fin >> dummy.start;
        fin >> dummy.finish;
        if (T.n < N)
            add(T, dummy);
    }
    ofstream fout("output.txt");
    for (int i = 1; i < 4; i++)
    {
        fout << T.el[T.n - i].number << " " << T.el[T.n - i].finish - T.el[T.n - i].start << endl;
    }
}