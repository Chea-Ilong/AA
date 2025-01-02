#include <iostream>

void swapByValue(int a, int b) {
    int temp = a;  
    a = b;         
    b = temp;      
} 
void swapByReference(int& a, int&b) {
   // TODO - You code to swap by references !  
      int temp = a;
    a = b;         
    b = temp; 
}

void swapByPointer(int* a, int* b) {
   // TODO - You code to swap by pointers !     
    int temp = *a;
    *a = *b;         
   *b = temp;   
}

// Log a message and the status of a and b in memory
void log(std::string message, int& a, int& b) {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << message << ":" << std::endl;
    
    std::cout << "A: Value=" << a << "\t\t\tAddress=" << &a << std::endl;         
    std::cout << "B: Value=" << b << "\t\t\tAddress=" << &b << std::endl;   
}

int main() {

    // 0 - INITIAL STATE
    int a = 5;
    int b = 10;
    log("Initial state", a, b);

    // 1 - SWAP BY VALUE
    swapByValue(a, b);
    log("After swaping by value", a, b);

    // 2 - SWAP BY REFERENCE
    swapByReference(a, b); 
    log("After swaping by reference", a, b);

    // 2 - SWAP BY POINTER
    swapByPointer(&a, &b); 
    log("After swaping by pointer", a, b);

    return 0;
}
