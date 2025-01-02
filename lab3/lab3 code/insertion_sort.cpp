#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int> &array)
{

    int n = array.size();
    for (int i = 1; i < n ; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j -1;
            }
            array[j + 1] = key;
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

    insertionsort(input);

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
