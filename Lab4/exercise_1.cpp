#include <iostream>
using namespace std;

class Array {
    int *data;
    int size;
    int length;

public:
    Array(int size) {
        this->size = size;
        this->length = 0;
        this->data = new int[size];
    }

    ~Array() {
        delete[] data;
    }

    void element(int data) {
        if (length == size) {
            newSize();
        }
        this->data[length] = data;
        length++;
    }

    int getLength() const {
        return length;
    }

    int getSize() const {
        return size;
    }

    int getIndex(int index) const {
        if (index >= 0 && index < length) {
            return data[index];
        }
        return -1;
    }

    void push(int data) {
        if (length == size) {
            newSize();
        }
        this->data[length] = data;
        length++;
    }

    void insertAt(int index, int value) {
        if (index < 0 || index > length) {
            return;
        }
        if (length == size) {
            newSize();
        }
        for (int i = length; i > index; i--) {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = value;
        length++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            return;
        }
        for (int i = index; i < length - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        length--;
    }

    void print() const {
        for (int i = 0; i < length; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    void newSize() {
        size = size * 2;
        int *newData = new int[size];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

int main() {
    Array arr(5);

    arr.element(10);
    arr.element(11);
    arr.element(12);
    arr.element(13);
    arr.element(14);

    arr.print();
    cout << "Current length: " << arr.getLength() << ", Current size: " << arr.getSize() << endl;

    cout << "The value at index 2: " << arr.getIndex(2) << endl;

    arr.push(5);
    cout << "After pushing value 5:" << endl;
    arr.print();
    cout << "Current length: " << arr.getLength() << ", Current size: " << arr.getSize() << endl;

    arr.insertAt(5, 99);
    cout << "After inserting 99 at index 5:" << endl;
    arr.print();
    cout << "Current length: " << arr.getLength() << ", Current size: " << arr.getSize() << endl;

    arr.removeAt(5);
    cout << "After removing value at index 5:" << endl;
    arr.print();
    cout << "Current length: " << arr.getLength() << ", Current size: " << arr.getSize() << endl;

    return 0;
}
