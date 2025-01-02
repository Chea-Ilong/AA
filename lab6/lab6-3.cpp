#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

struct Student
{
    string StudentID, Name, Gender;
    int MathScore, EnglishScore, ScienceScore;
};

int main()
{
    vector<Student> studentList;
    ifstream infile("C:\\Users\\MSI PC\\Desktop\\lab6\\data.csv", ios::in);
    ofstream outfile("C:\\Users\\MSI PC\\Desktop\\lab6\\data_report.csv", ios::out);

    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "Error: Could not open the file!" << endl;
        return 1;
    }

    string line;
    getline(infile, line);
    while (getline(infile, line))
    {
        stringstream ss(line);
        Student student;
        string mathScore, englishScore, scienceScore;
        getline(ss, student.StudentID, ',');
        getline(ss, student.Name, ',');
        getline(ss, student.Gender, ',');
        getline(ss, mathScore, ',');
        getline(ss, englishScore, ',');
        getline(ss, scienceScore, ',');

        student.MathScore = stoi(mathScore);
        student.EnglishScore = stoi(englishScore);
        student.ScienceScore = stoi(scienceScore);

        studentList.push_back(student);
    }

    int totalStudents = studentList.size();
    int maleCount = 0, femaleCount = 0;
    int maxScore = 0;
    int minScore = INT_MAX;
    int totalscore;

    for (const auto &student : studentList)
    {

        if (student.Gender == "M")
        {
            maleCount++;
        }
        else if (student.Gender == "F")
        {
            femaleCount++;
        }

        totalscore = student.MathScore + student.EnglishScore + student.ScienceScore;

        if (totalscore > maxScore)
        {
            maxScore = totalscore;
        }

        if (totalscore < minScore)
        {
            minScore = totalscore;
        }
    }

    outfile << "Total Students:" << totalStudents << endl;
    outfile << "Males:" << maleCount << endl;
    outfile << "Females:" << femaleCount << endl;
    outfile << "Max Score:" << maxScore << endl;
    outfile << "Min Score:" << minScore << endl;

    infile.close();
    outfile.close();

    cout << "Data report has been written to data_report.csv" << endl;

    return 0;
}

