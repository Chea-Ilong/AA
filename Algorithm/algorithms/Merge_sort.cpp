#include <bits/stdc++.h>
using namespace std;

int comparisonCount = 0;
int assignmentCount = 0;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        assignmentCount++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        assignmentCount++;
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisonCount++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        assignmentCount++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        assignmentCount++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        assignmentCount++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printVector(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = { 6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
        36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
        73, 92, 40, 89, 47, 78, 80, 100, 2, 60};
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);

    cout << "\nTotal comparisons: " << comparisonCount << endl;
    cout << "Total swaps: " << assignmentCount << endl;

    return 0;
}
