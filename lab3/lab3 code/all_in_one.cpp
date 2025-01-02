#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Bubble Sort
void bubblesort(vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionsort(vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        int minValue = array[i];
        for (int j = i + 1; j < n; j++) {
            if (array[j] < minValue) {
                minIndex = j;
                minValue = array[j];
            }
        }
        array[minIndex] = array[i];
        array[i] = minValue;
    }
}

// Insertion Sort
void insertionsort(vector<int> &array) {
    int n = array.size();
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Utility function to generate an array of random numbers
vector<int> generateRandomArray(int size) {
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000;  
    }
    return array;
}

// Function to measure the execution time of a sorting algorithm using <chrono>
void measureSortingTime(void (*sortFunction)(vector<int>&), vector<int> array, const string &sortName, int repeats = 5) {
    double total_time = 0.0;

    for (int i = 0; i < repeats; i++) {
        vector<int> tempArray = array;  // Copy the array each time for accurate measurement
        auto start = chrono::high_resolution_clock::now();
        sortFunction(tempArray);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> time_taken = end - start;
        total_time += time_taken.count();
    }
    
    double average_time = total_time / repeats;
    cout << sortName << " average time over " << repeats << " runs: " << fixed << setprecision(6) << average_time << " seconds" << endl;
}

int main() {
    srand(time(0));  // Initialize random seed

    const int N = 5000;  // Increase size of the arrays for more measurable times

    // Generate an identical array for each algorithm
    vector<int> array1 = generateRandomArray(N);
    vector<int> array2 = array1;  // Copy array1
    vector<int> array3 = array1;  // Copy array1

    // Measure and print sorting times
    cout << "Sorting " << N << " elements:" << endl;
    measureSortingTime(bubblesort, array1, "Bubble Sort", 3);
    measureSortingTime(selectionsort, array2, "Selection Sort", 3);
    measureSortingTime(insertionsort, array3, "Insertion Sort", 3);

    return 0;
}
