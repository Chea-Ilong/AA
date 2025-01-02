#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Book
{
    string ISBN, title, category, authors, price, publishedYear;
    Book *next;
};

class LinkedList
{

    Book *head, *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    }
    ~LinkedList()
    {
        while (head)
        {
            Book *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertBegin(const string &ISBN, const string &title, const string &category, const string &authors, const string &price, const string &publishedYear)
    {

        Book *b = new Book{ISBN, title, category, authors, price, publishedYear, head};
        head = b;
        size++;
    }

    void displayList()
    {
        Book *t;
        t = head;
        for (int i = 0; i < size; i++)
        {

            cout << ". ISBN: " << t->ISBN << ", Title: " << t->title << ", Category: " << t->category << ", Authors: " << t->authors << ", Price: " << t->price << ", Published Year: " << t->publishedYear << endl;
            t = t->next;
        }
    }

    void csvSplit(const string &line, string &ISBN, string &title, string &category, string &authors, string &price, string &publishedYear)
    {
        stringstream ss(line);
        getline(ss, ISBN, ',');
        getline(ss, title, ',');
        getline(ss, category, ',');
        getline(ss, authors, ',');
        getline(ss, price, ',');
        getline(ss, publishedYear, ',');
    }
};
int main()
{
    LinkedList *mylist = new LinkedList;
    ifstream myfile;
    myfile.open("C:\\Users\\MSI PC\\Desktop\\lab6\\book-list.csv", ios::in);

    if (!myfile.is_open())
    {
        cout << "Error: Could not open the file!" << endl;
        return 1;
    }

    string line;
    while (getline(myfile, line))
    {
        string ISBN, title, category, authors, price, publishedYear;
        mylist->csvSplit(line, ISBN, title, category, authors, price, publishedYear);
        mylist->insertBegin(ISBN, title, category, authors, price, publishedYear);
    }

    mylist->displayList();
    myfile.close();
    delete mylist;
    return 0;
}
