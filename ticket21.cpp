#include <iostream>
#include <fstream>

using namespace std;

struct dat
{
    float elem;
    char name[25];
};

struct tree
{
    tree *right;
    tree *left;
    dat info;
};

void addTreeElement(dat dummy, tree *&node)
{
    if (node == nullptr)
    {
        node = new tree;
        node->info = dummy;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (dummy.elem < node->info.elem)
    {
        addTreeElement(dummy, node->left);
    }
    else
    {
        addTreeElement(dummy, node->right);
    }
}

void delTreeMaxElement(tree *&node)
{
    if (node->right != nullptr)
    {
        delTreeMaxElement(node->right);
    }
    else if (node->left == nullptr)
    {
        node = nullptr;
    }
    else if (node->left != nullptr)
    {
        node = node->left;
    }
    else
    {
        node->left = node;
    }
}

void printTree(tree *&node)
{
    if (node != nullptr)
    {
        printTree(node->right);
        printTree(node->left);
        cout << node->info.name << " " << node->info.elem << endl;
    }
}

int main()
{
    ifstream input_file("ticket21.txt");
    tree *root;
    root = nullptr;
    dat dummy;
    while (!input_file.eof())
    {
        input_file >> dummy.name;
        input_file >> dummy.elem;
        addTreeElement(dummy, root);
    }
    printTree(root);
    cout << "---------------" << endl;
    delTreeMaxElement(root);
    printTree(root);
    cout << "---------------" << endl;
    delTreeMaxElement(root);
    printTree(root);
}