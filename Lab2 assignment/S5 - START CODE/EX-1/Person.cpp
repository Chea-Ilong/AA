#include <iostream>
#include <string>
using namespace std;

class Person {
	// Write you code here
    public:
    string lastName;
    string firstName;
    int securityNumber;

    Person (string first, string last, int security){
        this->firstName = first;
        this->lastName = last;
        this->securityNumber = security;
    }
    void setFirstName(string name){
         firstName = name;
    };
    string toString(){
       return  "First Name: "+ firstName + " Last Name:  " +lastName + " Security NUmber: " + to_string(securityNumber);

};

};
int main() {
    Person ronan("ronan", "ogor, ", 4785);

    ronan.setFirstName("ronano");
    std::cout << ronan.toString() << std::endl;

    return 0;
}
