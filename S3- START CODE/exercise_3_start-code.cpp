#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define DECIMAL_DIGIT 2

struct Student {
    int id;
    string name;
    int* scores;
    int numScores;
};

int main() {
    int n;
    // Step 1: Prompt user for the number of students
    do {
        cout << "Enter the number of students: ";
        cin >> n;
    } while (n <= 0);

    // Step 2: Dynamically allocate an array of Students
    Student* studentsize = new Student[n];

    // Step 3: Populate the student array with values
    for (int i = 0; i < n; ++i) {
        cout << "Enter the ID of student " << i + 1 << ": ";
        cin >> studentsize[i].id;
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> studentsize[i].name;
        cout << "Enter the number of scores: ";
        cin >> studentsize[i].numScores;
        
        // Allocate memory for the scores
        studentsize[i].scores = new int[studentsize[i].numScores];

        // Input each score
        for (int j = 0; j < studentsize[i].numScores; ++j) {
            cout << "Enter score " << j + 1 << ": ";
            cin >> studentsize[i].scores[j];
        }
    }

    // Step 4: Display the ID, Name, and average score of each student
   
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent number " << i + 1 << ": " << endl;
        cout << "Student name: " << studentsize[i].name << endl;
        cout << "Student ID: " << studentsize[i].id << endl;

        float sum = 0;
        for (int j = 0; j < studentsize[i].numScores; ++j) {
            sum += studentsize[i].scores[j];
        }

        float average = sum / studentsize[i].numScores;
        cout << "Student average score: " << average << endl;

        // Step 5: Free the allocated memory for the scores
        delete[] studentsize[i].scores;  // Free memory for scores
    }

    // Step 5: Free the allocated memory for studentsize
    delete[] studentsize;
    studentsize = nullptr;
    return 0;
}
