#include <iostream>
using namespace std;
int main()
{
   int n = 0, sum = 0;

    while (n != -1)
    {
        cout << "Input a number: ";
        cin >> n;

        if (n != -1)
        {
            sum += n;
        }
    }

    cout << "Total amount: " << sum;

    return 0;
}