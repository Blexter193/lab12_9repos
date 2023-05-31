#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
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
    
    if (value < root->data)
    {
        return search(root->left, value);
    }
    
    else
    {
        return search(root->right, value);
    }
}

void display(Node* root, int space, int highlightValue)
{
    if (root == nullptr)
    {
        return;
    }
    space += 4;
    display(root->right, space, highlightValue);
    cout << endl;
    for (int i = 4; i < space; i++)
    {
        cout << " ";
    }
    if (root->data == highlightValue)
    {
        cout << root->data << " <---" << endl;
    }
    else
    {
        cout << root->data << endl;
    }
    display(root->left, space, highlightValue);
}

Node* createBinaryTree(int elements[], int size)
{
    Node* root = nullptr;
    for (int i = 0; i < size; i++)
    {
        root = insert(root, elements[i]);
    }
    return root;
}

Node* createBinarySearchTree(int elements[], int size)
{
    Node* root = nullptr;
    for (int i = 0; i < size; i++)
    {
        root = insert(root, elements[i]);
    }
    return root;
}

Node* insertInOrder(Node* root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (value < parent->data)
    {
        parent->left = new Node(value);
    }
    else
    {
        parent->right = new Node(value);
    }

    return root;
}

Node* balanceBST(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    return root;
}

void inOrderTraversal(Node* root, vector<int>& nodes)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left, nodes);
        nodes.push_back(root->data);
        inOrderTraversal(root->right, nodes);
    }
}

Node* constructBST(vector<int>& nodes, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(nodes[mid]);
    root->left = constructBST(nodes, start, mid - 1);
    root->right = constructBST(nodes, mid + 1, end);

    return root;
}

Node* deleteLeafNode(Node* root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == value && root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }

    if (value < root->data)
    {
        root->left = deleteLeafNode(root->left, value);
    }
    else
    {
        root->right = deleteLeafNode(root->right, value);
    }

    return root;
}

Node* deleteNodeWithOneChild(Node* root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == value)
    {
        if (root->left != nullptr && root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
    }

    if (value < root->data)
    {
        root->left = deleteNodeWithOneChild(root->left, value);
    }
    else
    {
        root->right = deleteNodeWithOneChild(root->right, value);
    }

    return root;
}

Node* findMin(Node* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

Node* deleteNodeWithTwoChildren(Node* root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (value < root->data)
    {
        root->left = deleteNodeWithTwoChildren(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNodeWithTwoChildren(root->right, value);
    }
    else {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* minValueNode = findMin(root->right);
        root->data = minValueNode->data;
        root->right = deleteNodeWithTwoChildren(root->right, minValueNode->data);
    }

    return root;
}

Node* deleteSubtree(Node* root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == value)
    {
        
        return nullptr;
    }

    if (value < root->data)
    {
        root->left = deleteSubtree(root->left, value);
    }
    else
    {
        root->right = deleteSubtree(root->right, value);
    }

    return root;
}

void deleteBinaryTree(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

int main() {
    
    Node* root = nullptr;

    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    cout << "Бінарне дерево:" << endl;
    display(root, 0, 6);
    cout << endl;

    Node* bstRoot = nullptr;
    bstRoot = insert(bstRoot, 50);
    bstRoot = insert(bstRoot, 30);
    bstRoot = insert(bstRoot, 70);
    bstRoot = insert(bstRoot, 20);
    bstRoot = insert(bstRoot, 40);
    bstRoot = insert(bstRoot, 60);
    bstRoot = insert(bstRoot, 80);

    cout << "Бінарне дерево пошуку:" << endl;
    display(bstRoot, 0, 60);
    cout << endl;

    bstRoot = insert(bstRoot, 55);
    
    bstRoot = balanceBST(bstRoot);
    
    bstRoot = deleteLeafNode(bstRoot, 40);
    
    bstRoot = deleteNodeWithOneChild(bstRoot, 30);
    
    bstRoot = deleteNodeWithTwoChildren(bstRoot, 70);
    
    bstRoot = deleteSubtree(bstRoot, 60);
    
    int k = 55;
    bool found = search(bstRoot, k);
    if (found)
    {
        cout << "Елемент " << k << " знайдено в бінарному дереві пошуку." << endl;
    }
    else
    {
        cout << "Елемент " << k << " не знайдено в бінарному дереві пошуку." << endl;
    }
   
    return 0;
}

