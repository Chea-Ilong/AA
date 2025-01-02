#include <iostream>
using namespace std;

int main()
{
    int array[] = {
        6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
        36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
        73, 92, 40, 89, 47, 78, 80, 100, 2, 60
    };
    int n = sizeof(array) / sizeof(array[0]);

    int swapCount = 0;
    int comparisonCount = 0;

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << endl;

    for (int i = 1; i < n; ++i)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            comparisonCount++;
            array[j + 1] = array[j];
            j = j - 1;
            swapCount++;
        }
        array[j + 1] = key;
        comparisonCount++;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << endl;

    cout << "Total swaps: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;

    return 0;
}
