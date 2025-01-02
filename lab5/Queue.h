#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

class Queue
{
private:
    Node *front, *rear;
    int length;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        length = 0;
    };
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    };

    void enqueue(int enter)
    {
        Node *newNode;
        newNode = new Node;
        newNode->value = enter;
        newNode->next = nullptr;

        if (length == 0)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    };
    void dequeue()
    {

        if (length == 0)
        {
            cout << "The Queue is empty";
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            length--;
        }
    };
    int peek()
    {
        if (length == 0)
        {
            cout << "The Queue is empty";
            return -1;
        }
        return front->value;
    };
    bool isEmpty()
    {
        return (length == 0);
    };
    string print()
    {
        Node *t = front;
        string store = " ";
        while (t != nullptr)
        {
            store += to_string(t->value) + " ";
            t = t->next;
        }
        return store;
    };
    int size()
    {
        return length;
    };
};
