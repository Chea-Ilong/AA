#include <iostream>
using namespace std;

void exercise8(int *n, int *m)

{
    int t;
    t = *n;
    *n = *m;
    *m = t;
}

int main()
{
    int a = 10, b = 20;
    cout << "Before" << endl;
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;
    exercise8(&a, &b);
    cout << "After" << endl;
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;

    return 0;
}
