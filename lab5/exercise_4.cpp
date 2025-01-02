#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int ID;
    std::string name;
    int phone_number;
    std::string gender;
    std::string major;
    Student *next;
};

class Queue
{
private:
    Student *front, *rear;
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

    void enqueue(int ID,
                 string name,
                 int phone_number,
                 string gender,
                 string major)
    {
        Student *newNode;
        newNode = new Student;
        newNode->name = name;
        newNode->ID = ID;
        newNode->phone_number = phone_number;
        newNode->gender = gender;
        newNode->major = major;
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
            Student *temp = front;
            front = front->next;
            delete temp;
            length--;
        }
    };
    Student *peek()
    {
        if (length == 0)
        {
            cout << "The Queue is empty" << endl;
            return nullptr;
        }
        return front;
    };

    bool isEmpty()
    {
        return (length == 0);
    };
    void print()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty" << endl;
        }
        Student *t = front;
        while (t != nullptr)
        {
            cout << "ID: " << t->ID
                 << ", Name: " << t->name
                 << ", Phone: " << t->phone_number
                 << ", Gender: " << t->gender
                 << ", Major: " << t->major << endl;
            t = t->next;
        }
    }
    void print3()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty" << endl;
        }
        Student *t = front;
        int count = 0;
        while (t != nullptr && count != 3)
        {

            cout << "ID: " << t->ID
                 << ", Name: " << t->name
                 << ", Phone: " << t->phone_number
                 << ", Gender: " << t->gender
                 << ", Major: " << t->major << endl;
            count++;
            t = t->next;
        }
    };
    int size()
    {
        return length;
    };
};

int main()
{
    Queue myqueue;
    int choice;
    do
    {
        cout << "\nQueue Menu:" << endl;
        cout << "1. Enqueue student" << endl;
        cout << "2. Dequeue student" << endl;
        cout << "3. Print all students" << endl;
        cout << "4. Print first 3 students" << endl;
        cout << "5. Check queue size" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ID, phone_number;
            string name, gender, major;

            cout << "Enter student ID: ";
            cin >> ID;
            cin.ignore();

            cout << "Enter student name: ";
            getline(cin, name);

            cout << "Enter student phone number: ";
            cin >> phone_number;

            cout << "Enter student gender: ";
            cin >> gender;

            cout << "Enter student major: ";
            cin.ignore();
            getline(cin, major);

            myqueue.enqueue(ID, name, phone_number, gender, major);
            cout << "Student added to the queue." << endl;
            break;
        }
        case 2:
            myqueue.dequeue();
            break;
        case 3:
            myqueue.print();
            break;
        case 4:
            myqueue.print3();
            break;
        case 5:
            cout << "Queue size: " << myqueue.size() << endl;
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
