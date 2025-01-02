#include <iostream>
using namespace std;
struct Item
{
	int id;
	string name;
	double price;
};

int main()
{
	int n;
	// Step 1: Prompt user for the number of Items
	do
	{
		cout << "Enter the number of Items: ";
		cin >> n;
	}while (n <= 0);

	// Step 2: Dynamically allocate an array of Items
	Item* itemsArray = new Item[n];

	// Step 3: Populate the item array with values
	for (int i = 0; i < n; ++i){
		cout << "Enter the ID of Item " << i + 1 << ": ";
		cin >> itemsArray[i].id;
		cout << "Enter the name of Item " << i + 1 << ": ";
		cin >> itemsArray[i].name;
		cout << "Enter the price of Item " << i + 1 << ": ";
		cin >> itemsArray[i].price;
	}
	// Step 4: Calculate and print the total memory usage
	
	cout << "Total memory used: " << sizeof(Item) * n << " bytes" << endl;
	
    // Step 5: Display the contents of the array
    cout << "Array contents:" << endl;    
    for (int i = 0; i < n; ++i){
		cout << "Element " << i + 1 << ": ID = " << itemsArray[i].id << ", Value = " << itemsArray[i].name << ", Price = " << itemsArray[i].price << std::endl;
	}
    // Step 6: Free the allocated memory
    delete[] itemsArray;
	itemsArray = nullptr;

	return 0;
}        