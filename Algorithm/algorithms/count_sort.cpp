#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& inputArray, int &swapCount, int &comparisonCount) {
    int N = inputArray.size();
    int M = 0;

    // Find the maximum element to determine the range
    for (int i = 0; i < N; i++) {
        M = max(M, inputArray[i]);
        comparisonCount++; // Counting comparisons for finding the max
    }

    // Initialize countArray
    vector<int> countArray(M + 1, 0);

    // Populate countArray with the frequency of each element
    for (int i = 0; i < N; i++) {
        countArray[inputArray[i]]++;
        swapCount++; // Counting as an assignment to countArray
    }

    // Calculate cumulative count
    for (int i = 1; i <= M; i++) {
        countArray[i] += countArray[i - 1];
        swapCount++; // Counting each cumulative assignment
    }

    // Build outputArray based on cumulative count
    vector<int> outputArray(N);
    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
        swapCount++; // Counting each assignment to outputArray as a "swap"
    }

    return outputArray;
}

int main() {
    vector<int> inputArray = {6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
                              36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
                              73, 92, 40, 89, 47, 78, 80, 100, 2, 60};

    int swapCount = 0;
    int comparisonCount = 0;

    // Print original array
    cout << "Original array: ";
    for (int i = 0; i < inputArray.size(); i++)
        cout << inputArray[i] << " ";
    cout << endl;

    vector<int> outputArray = countSort(inputArray, swapCount, comparisonCount);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < inputArray.size(); i++)
        cout << outputArray[i] << " ";
    cout << endl;

    // Print counts
    cout << "Total swap: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;

    return 0;
}
