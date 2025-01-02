#include "Node.h"
#include <string.h>

class Stack {
private:
    Node* top;     // Pointer to the top of the stack
    int length;      // Keeps track of the stack size

public:
    Stack() {       // Constructor
        // your code here
    }

    ~Stack() {      
        while (!isEmpty()) {
            pop(); 
        }
    }

    // Push an element onto the stack
    void push(int value) {
       // your code here
    }

    // Pop the top element from the stack
    void pop() {
        // your code here
    }

    // Peek the top element without removing it
    int peek() {
        // your code here
    }

    // Check if the stack is empty
    bool isEmpty() {
       // your code here
    }

    // Get the current length of the stack
    int size() {
        return length;
    }
    // Convert the stack to a string representation
    std::string toString() {
       // your code here
        
    }
};
