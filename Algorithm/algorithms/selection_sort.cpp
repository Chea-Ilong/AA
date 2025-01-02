#include <iostream>
using namespace std;


int main() {
    int n = 50;
    int array[n] = {
        6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
        36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
        73, 92, 40, 89, 47, 78, 80, 100, 2, 60
    };
    int swapCount = 0;
    int comparisonCount = 0;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            comparisonCount++;
            if (array[min_index] > array[j]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(array[min_index], array[i]);
            swapCount++;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Total swaps: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;

    return 0;
}
