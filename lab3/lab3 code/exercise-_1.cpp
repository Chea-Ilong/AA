#include <iostream>
#include <vector>
using namespace std;

bool issorted(vector<int>& array)
{
    int n = array.size();
    for (int i = 0; i < n-1; i++)
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

    vector<int> input1 = {1, 2, 8, 10, 49};
    vector<int> input2 = {1, 2, 8, 6, 49};
    vector<int> input3 = {3, 3, 3, 3};
    vector<int> input4 = {};

    cout << boolalpha;
    cout << "Output: " << issorted(input1) << endl;
    cout << "Output: " << issorted(input2) << endl;
    cout << "Output: " << issorted(input3) << endl;
    cout << "Output: " << issorted(input4) << endl;

    return 0;
}