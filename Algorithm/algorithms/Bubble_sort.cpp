#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n = 50;
    int swapCount = 0;
    int comparisonCount = 0; // Counter for comparisons
    int array[n] = {
        6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
        36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
        73, 92, 40, 89, 47, 78, 80, 100, 2, 60
    };

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparisonCount++; 
            if (array[j] > array[j + 1]) {
                swapCount++; 
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Total swaps: " << swapCount << endl; // Output the total number of swaps
    cout << "Total comparisons: " << comparisonCount << endl; // Output the total number of comparisons
    
    // Total operations (considering both swaps and comparisons)
    int totalOperations = swapCount + comparisonCount;
    cout << "Total operations (swaps + comparisons): " << totalOperations << endl;

    return 0;
}
