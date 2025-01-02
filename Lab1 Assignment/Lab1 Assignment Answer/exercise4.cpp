#include <iostream>
using namespace std;

void exercise4(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1.0 / i;
        cout << "1/" << i << " + ";
    }
    cout << "\b\b= " << sum << endl;
}

int main()
{

    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    exercise4(n);

    return 0;
}
