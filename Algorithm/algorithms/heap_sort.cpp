#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i, int& comparisonCount, int& assignmentCount) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        comparisonCount++;
        if (arr[l] > arr[largest]) {
            largest = l;
        }
    }

    if (r < n) {
        comparisonCount++;
        if (arr[r] > arr[largest]) {
            largest = r;
        }
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        assignmentCount++;
        heapify(arr, n, largest, comparisonCount, assignmentCount);
    }
}

void heapSort(vector<int>& arr, int& comparisonCount, int& assignmentCount) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comparisonCount, assignmentCount);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        assignmentCount++;
        heapify(arr, i, 0, comparisonCount, assignmentCount);
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = { 6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
                        36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
                        73, 92, 40, 89, 47, 78, 80, 100, 2, 60 };

    cout << "Original array is: \n";
    printArray(arr);

    int comparisonCount = 0;
    int assignmentCount = 0;

    heapSort(arr, comparisonCount, assignmentCount);

    cout << "Sorted array is: \n";
    printArray(arr);

    cout << "Total comparisons: " << comparisonCount << endl;
    cout << "Total assignments (swaps): " << assignmentCount << endl;

    return 0;
}
