#include <iostream>
using namespace std;

void shellSort(int arr[], int n, int& swapCount, int& comparisonCount)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                comparisonCount++;
                arr[j] = arr[j - gap];
                swapCount++;
            }
            arr[j] = temp;
            swapCount++;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {6, 21, 7, 61, 59, 84, 70, 40, 51, 99, 67, 75, 82, 43, 69, 84, 43, 44, 61, 6,
                 36, 53, 5, 4, 91, 15, 56, 50, 22, 74, 82, 55, 7, 86, 61, 19, 79, 2, 85, 32,
                 73, 92, 40, 89, 47, 78, 80, 100, 2, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int swapCount = 0, comparisonCount = 0;

    cout << "Array before sorting: \n";
    printArray(arr, n);

    shellSort(arr, n, swapCount, comparisonCount);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);
    
    cout << "\nTotal swaps: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;

    return 0;
}
