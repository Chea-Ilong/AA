#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedlist
{
    int length;
    Node *head;

public:
    linkedlist()
    {
        length = 0;
        head = NULL;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        length++;
    }

    ~linkedlist()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    int getLength() const
    {
        return length;
    }

    int get(int index) const
    {
        if (index >= 0 && index < length)
        {
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->data;
        }
        return -1; 
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL) 
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }

    void insertAt(int index, int value)
    {
        if (index >= 0 && index <= length) 
        {
            if (index == 0)
            {
                insert(value);
            }
            else
            {
                Node *newNode = new Node(value);
                Node *current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                length++;
            }
        }
    }

    void removeAt(int index)
    {
        if (index >= 0 && index < length) 
        {
            Node *current = head;
            if (index == 0)
            {
                head = current->next;
                delete current;
            }
            else
            {
                Node *previous = NULL;
                for (int i = 0; i < index; i++)
                {
                    previous = current;
                    current = current->next;
                }
                previous->next = current->next;
                delete current;
            }
            length--;
        }
    }

    void print() const
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    linkedlist list;
    list.insert(13);
    list.insert(12);
    list.insert(11);
    list.insert(10);
    list.print();
    cout << "Current length: " << list.getLength() << endl;

    cout << "Value at index 1: " << list.get(1) << endl;

    list.push(99);
    cout << "After pushing value 99: " << endl;
    list.print();
    cout << "Current length: " << list.getLength() << endl;

    list.insertAt(1, 77);
    cout << "After inserting value 77 at index 1: " << endl;
    list.print();
    cout << "Current length: " << list.getLength() << endl;

    list.removeAt(3);
    cout << "After removing value at index 3: " << endl;
    list.print();
    cout << "Current length: " << list.getLength() << endl;

    return 0;
}
