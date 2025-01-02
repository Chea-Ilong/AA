#include <iostream>
using namespace std;

int swapCount = 0;        // Counter for swaps
int comparisonCount = 0;  // Counter for comparisons

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        comparisonCount++; // Counting comparison
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        swapCount++; // Counting swap when placing in count array
    }

    // Change count[i] so that count[i] contains the actual position in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        swapCount++; // Counting swap when modifying count array
    }

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        swapCount++; // Counting swap when placing in output array
    }

    // Copy the output array to arr[]
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        swapCount++; // Counting swap when copying back to original array
    }
}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = { 6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
                  36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
                  73, 92, 40, 89, 47, 78, 80, 100, 2, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Original array: ";
    print(arr, n);
    
    radixsort(arr, n);
    
    cout << "\nSorted array: ";
    print(arr, n);
    
    cout << "\nTotal swaps: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;

    return 0;
}
