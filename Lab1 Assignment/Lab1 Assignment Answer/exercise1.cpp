#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, delta, X1, X2;

    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;
    cout << a << "x^2" << " + " << b << "x" << " + " << c << " = 0" << endl;
    delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        X1 = (-b + sqrt(delta)) / (2 * a);
        X2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "X1 = " << X1 << endl;
        cout << "X2 = " << X2 << endl;
    }
    else if (delta == 0)
    {
        X1 = X2 = -b / (2 * a);
        cout << "Roots are real and the same." << endl;
        cout << "X1 = X2 = " << X1 << endl;
    }
    else
    {

        cout << "the equation has no real roots" << endl;
    }

    return 0;
}
