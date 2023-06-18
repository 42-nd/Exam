//13) В текстовом файле дана последовательность слов.Написать подпрограмму,
//которая помещает элементы этой последовательности в дерево поиска.
//Используя эту подпрограмму напечатать слова последовательности в
//алфавитном порядке.
#include <iostream>
#include <fstream>

using namespace std;

struct tree
{
    string value;
    tree* left;
    tree* right;
};

tree* addnode(string x, tree* T)
{
    if (T == NULL)
    {
        T = new tree;
        T->value = x;
        T->left = NULL;
        T->right = NULL;
    }
    else if (x < T->value)
        T->left = addnode(x, T->left);
    else
        T->right = addnode(x, T->right);
    return T;
}

void treeprint(tree* T)
{
    if (T != NULL)
    {
        treeprint(T->left);
        cout << T->value << " ";
        treeprint(T->right);
    }
}

int main()
{
    ifstream fin;
    fin.open("tree.txt");

    string word;
    fin >> word;

    tree* root = NULL;
    root = addnode(word, root);

    while (!fin.eof())
    {
        string word;
        fin >> word;
        addnode(word, root);
    }

    treeprint(root);
    cout << endl;

    return 0;
}