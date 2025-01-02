#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<int> &array)
{

    int n = array.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
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

    vector<int> input = {10, 7, 5, 3, 1};
    
    bubblesort(input);

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
