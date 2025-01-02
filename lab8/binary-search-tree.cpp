#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
    Node *root;
    int size;

public:
    BinaryTree()
    {
        size = 0;
        root = nullptr;
    }
    ~BinaryTree()
    {
        deleteTree(root);
        root = nullptr;
    }
    void deleteTree(Node *node)
    {
        if (node != nullptr)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    Node *insert(Node *root, int newdata)
    {
        if (root == nullptr)
        {
            root = new Node;
            root->left = nullptr;
            root->right = nullptr;
            root->data = newdata;
            size++;
        }
        else if (newdata < root->data)
        {
            root->left = insert(root->left, newdata);
        }
        else if (newdata > root->data)
        {
            root->right = insert(root->right, newdata);
        }
        // Duplicates are ignored
        return root;
    }

    void add(int newdata)
    {
        root = insert(root, newdata);
    }
    bool search(Node *root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (data == root->data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }

    bool search(int newdata)
    {
        return search(root, newdata);
    }

    void preOrder(Node *node)
    { // DLR (data, left, right)
        if (node != nullptr)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void preOrderTraversal()
    {
        preOrder(root);
    }

    void inOrder(Node *node)
    { // LDR (left, data, right)
        if (node != nullptr)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void inOrderTraversal()
    {
        inOrder(root);
    }
    void postOrder(Node *node)
    { // LRD (left, right, data)
        if (node != nullptr)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    void postOrderTraversal()
    {
        postOrder(root);
    }
    int treesize()
    {
        return size;
    }

    Node *getSuccessor(Node *curr)
    {
        curr = curr->right;
        while (curr != nullptr && curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    Node *delNode(Node *root, int x)
    {

        if (root == nullptr)
            return root;

        if (root->data > x)
            root->left = delNode(root->left, x);
        else if (root->data < x)
            root->right = delNode(root->right, x);

        else
        {

            // Cases when root has 0 children
            // or only right child
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // When root has only left child
            if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // When both children are present
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = delNode(root->right, succ->data);
        }
        return root;
    }
    bool remove(int newdata)
    {
        if (!search(newdata))
        {
            cout << "Element not found in the BST.\n";
            return false;
        }
        root = delNode(root, newdata);
        size--;
        return true;
    }
};

int main()
{
    BinaryTree tree;

    ifstream infile;
    infile.open("C:\\Users\\MSI PC\\Desktop\\lab8\\Lab08_Data_ID_Numbers_1M (1).csv", ios::in);

    if (!infile.is_open())
    {
        cout << "Error in file opening" << endl;
        return 1;
    }

    int value;
    string line;
    getline(infile, line);
    while (infile >> value)
    {
        tree.add(value);
    }

    int opt, key;

    while (1)
    {

        cout << "\nMenu:\n";
        cout << "1. Show PreOrder\n";
        cout << "2. Show InOrder\n";
        cout << "3. Show PostOrder\n";
        cout << "4. Search\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "BST size: " << tree.treesize() << endl;
        cout << "Choose an option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Preorder Traversal: ";
            tree.preOrderTraversal();
            cout << endl;
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tree.inOrderTraversal();
            cout << endl;
            break;

        case 3:
            cout << "Postorder Traversal: ";
            tree.postOrderTraversal();
            cout << endl;
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> key;
            if (tree.search(key))
                cout << "Found.\n";
            else
                cout << "Not found.\n";
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> key;
            if (tree.remove(key))
                cout << "Value deleted.\n";
            else
                cout << "Value not found.\n";
            break;

        case 6:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
