#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorderTraversal(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

bool search(Node* root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (value == root->data)
    {
        return true;
    }
    
    else if (value < root->data)
    {
        return search(root->left, value);
    }
    
    else
    {
        return search(root->right, value);
    }
}

int main()
{
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Непорядковий обхід: ";
    inorderTraversal(root);
    cout << endl;

    int searchValue = 60;
    bool found = search(root, searchValue);
    if (found)
    {
        cout << searchValue << " - цей елемент входить у бінарне дерево пошуку" << endl;
    }
    
    else
    {
        cout << searchValue << " - цей елемент не входить у бінарне дерево пошуку" << endl;
    }

    return 0;
}

