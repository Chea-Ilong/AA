#include "Stack.h"
#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{

    // Test cases for stack class
    Stack mystack;
    cout << "Stack: " << endl;
    cout << "Test 1: " << endl;
    mystack.push(11);
    mystack.push(22);
    mystack.push(33);
    mystack.push(44);
    cout << "Stack contents: " << mystack.print() << endl;
    cout << "Stack size: " << mystack.size() << endl;
    cout << "Test 2: " << endl;
    mystack.pop();
    cout << "Stack contents after pop: " << mystack.print() << endl;
    mystack.pop();
    cout << "Stack contents after pop: " << mystack.print() << endl;
    cout << "Stack size: " << mystack.size() << endl;
    cout << "Is stack empty? " << (mystack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Peeking " << mystack.peek() << endl;
    cout << "Test 3: " << endl;
    mystack.pop();
    mystack.pop();
    cout << "Stack contents after pop x 2" << endl;
    cout << "Is stack empty? " << (mystack.isEmpty() ? "Yes" : "No") << endl;

    // Test cases for Qeueu class
    Queue myQueue;
    cout << "Queue: " << endl;
    cout << "Test: " << endl;
    myQueue.enqueue(11);
    myQueue.enqueue(22);
    myQueue.enqueue(33);
    cout << myQueue.print() << endl;
    myQueue.dequeue();
    cout << myQueue.print() << endl;
    cout << "Front of the queue is: " << myQueue.peek() << endl;
    cout << "Queue is empty: " << boolalpha << myQueue.isEmpty() << endl;
    cout << "Queue size is: " << myQueue.size() << endl;

    
    return 0;
}