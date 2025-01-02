#include <iostream>
#include <vector>
using namespace std;

void selectionsort(vector<int> &array)
{

    int n = array.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        int minValue = array[i];
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < minValue)
            {
                minIndex = j;
                minValue = array[j];
            }
        }
        array[minIndex] = array[i];
        array[i] = minValue;
    }
}
bool issort(vector<int> &array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    vector<int> input = {10, 7, 5, 3, 8, 6, 1};

    selectionsort(input);

    cout << "Sorted array: ";

    for (int num : input)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << boolalpha;
    cout << issort(input) << endl;

    return 0;
}
