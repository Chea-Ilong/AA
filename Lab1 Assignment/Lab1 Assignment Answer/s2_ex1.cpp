#include <iostream>
using namespace std;

/**
 * Return whether the given number if inside the given range
 * @param number : the number
 * @param min : the range min
 * @param max : the range max
 * @return true if inside the range, false otherwise
 */
bool isInside(int number, int min, int max)
{
    // TODO

    if (number >= min && number <= max)
    {
        return true;
    }
    else {
        return false;
    }
}

int main()
{

    // 1-  Input the number
    // TODO
    
    int min, max, number;

    cout << "Input one number: ";
    cin >> number;

    // 2 - Input the range
    do
    {
        if (min > max)
        {
            cout << "Min should be smaller than Max" << endl;
        }
        cout << "Enter the range min: ";
        cin >> min;

        cout << "Enter the range max: ";
        cin >> max;
        
    } while (min > max);
    // BONUS : If the user accidentally enters a minimum value that is larger
    // than the maximum value, ask them to enter the values again.

    // TODO

    // 3-  Check if the number is inside the range
    if (isInside(number, min, max) == true)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    // TODO
 
    return 0;
}