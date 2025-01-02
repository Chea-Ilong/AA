#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee
{
    string name, gender, email, age, salary;
};

int main()
{
    const int n = 10;
    Employee employees[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for Employee " << (i + 1) << ":" << endl;

        cout << "Name: ";
        cin >> employees[i].name;

        cout << "Age: ";
        cin >> employees[i].age;

        cout << "Gender: ";
        cin >> employees[i].gender;

        cout << "Email: ";
        cin >> employees[i].email;

        cout << "Salary: ";
        cin >> employees[i].salary;

        cout << endl;
    }

    ofstream myfile;
    myfile.open("C:\\Users\\MSI PC\\Desktop\\lab6\\exercise-2.csv", ios::out);

    if (!myfile.is_open())
    {
        cout << "Error: Could not open the file!" << endl;
        return 1;
    }

    myfile << "Name,Age,Gender,Email,Salary" << endl;

    for (int i = 0; i < n; i++)
    {
        myfile << employees[i].name << ","
               << employees[i].age << ","
               << employees[i].gender << ","
               << employees[i].email << ","
               << employees[i].salary << endl;
    }

    myfile.close();

    return 0;
}
