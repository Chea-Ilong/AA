#include <iostream>
using namespace std;
int main()
{

    int x, y;

    cout << "Input two integer: ";
    cin >> x >> y;

    int *p1 = &x;
    int *p2 = &y;

    cout << "Display address and value of x: " << *p1 << " And " << &p1 << endl;
    cout << "Display address and value of y: " << *p2 << " And " << &p2 << endl;

    return 0;
}