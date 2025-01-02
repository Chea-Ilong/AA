#include <iostream>
using namespace std;

    bool issorted(int array[] , int size){

       
        for (int i = 0; i < size; i++)
        {
           if ( array[i] > array[i+1]){
            
                return false;
           }
        }
            return true;
        
    }


int main (){
     int n ;
    cout << "Enter the size the size of the array: " ;
    cin >> n;
   
    int array[n];


    for (int i = 0; i < n; i++)
    {
        cout << "Enter for array number" << i+1 << ": ";
        cin >> array[i];
    }

    if (issorted (array ,n) == true){
        cout << "True";
    }else{
        cout << "False";
    }

    







    return 0;
}