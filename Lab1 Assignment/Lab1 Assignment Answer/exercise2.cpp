#include <iostream>
using namespace std;
int main()
{

    for (int i = 1; i <= 1000; i++)
    {
        if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500)
        {
            continue;
        }
        cout << i << " ";
    }

    return 0;
}