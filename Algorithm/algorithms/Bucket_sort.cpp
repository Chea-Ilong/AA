#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& bucket, int& comparisonCount, int& assignmentCount) {
    for (int i = 1; i < bucket.size(); ++i) {
        int key = bucket[i];
        assignmentCount++;
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            comparisonCount++;
            bucket[j + 1] = bucket[j];
            assignmentCount++;
            j--;
        }
        bucket[j + 1] = key;
        assignmentCount++;
    }
}

void bucketSort(int arr[], int n, int& comparisonCount, int& assignmentCount) {
    // Create n empty buckets
    vector<vector<int>> buckets(n);

    // Put array elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bi = arr[i] * n / 101; // Ensure the values map correctly to the bucket index
        buckets[bi].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], comparisonCount, assignmentCount);
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
            assignmentCount++;
        }
    }
}

int main() {
    int arr[] = {6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
        36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
        73, 92, 40, 89, 47, 78, 80, 100, 2, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array is: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int comparisonCount = 0;
    int assignmentCount = 0;

    bucketSort(arr, n, comparisonCount, assignmentCount);

    cout << "Sorted array is: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total comparisons: " << comparisonCount << endl;
    cout << "Total assignments: " << assignmentCount << endl;

    return 0;
}
