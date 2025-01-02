#include <iostream>
#include <algorithm>
using namespace std;
int sumSuite(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        cout << i << " ";
        if (i != n)
        {
            cout << "+ ";
        }
            sum += i;
    }
    cout  << " = " << sum << endl;
    return sum;
}

int sumDigit(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum + n;
}

void printSum(int n)
{
    int count = 0;
    int num = n;
    int a[100];
    while (n != 0)
    {
        a[count] = n % 10;
        n = n / 10;
        count++;
    }

    int count_v2 = count - 1;
    while (count > 0)
    {
        cout << a[count_v2];
        if (count > 1)
        {
            cout << "+";
        }
        count--;
        count_v2--;
    }
}
int main()
{
    int userInput;
    int one;
    while (1)
    {
        cout << "1.sumSuite" << endl;
        cout << "2.sumDigit" << endl;
        cout << "Enter one of the above: ";
        cin >> one;
        if (one > 2 || one < 0){
            cout << "Please enter the choice above!!!" << endl;
        }
        switch (one)
        {
        case 1:
            cout << "Enter a number: ";
            cin >> userInput;
            sumSuite(userInput);
            break;
        case 2:
            cout << "Enter a number: ";
            cin >> userInput;
            printSum(userInput);
            cout << " = "<< sumDigit(userInput) << endl;
            break;
        }
    }

    return 0;
}
