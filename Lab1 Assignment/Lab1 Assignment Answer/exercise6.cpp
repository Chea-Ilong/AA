#include <iostream>
using namespace std;
struct person
{
    string name;
    int age;
    string zodiac_sign;
};

int main()
{

    int n = 0;
    do
    {
        if (n > 20)
        {
            cout << "The max number is 20!!\n";
        }
        cout << "How many people to store (max:20): ";
        cin >> n;
    } while (n > 20);
    person people[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Person " << i + 1 << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, people[i].name);
        cout << "Age: ";
        cin >> people[i].age;
        cout << "Zodiac sign: ";
        cin >> people[i].zodiac_sign;
    }

    int oldest = 0;
    for (int i = 0; i < n; i++)
    {
        if (people[i].age > oldest)
        {
            oldest = people[i].age;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "=======================\n";
        cout << "Person" << i + 1 << endl;
        cout << "Name: " << people[i].name << endl;
        cout << "Age: " << people[i].age << endl;
        cout << "Zodiac sign: " << people[i].zodiac_sign << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (people[i].age == oldest)
        {
            cout << "=======================\n";
            cout << "Oldest person" << endl;
            cout << "Name: " << people[i].name << endl;
            cout << "Age: " << people[i].age << endl;
            cout << "Zodiac sign: " << people[i].zodiac_sign << endl;
        }
    }
    return 0;
}