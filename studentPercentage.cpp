#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int studid;
    string name;
    int marks[5];
    float percentage;

    float calculatePercentage() {
        float totalMarks = 0;
        for (int i = 0; i < 5; ++i) {
            totalMarks += marks[i];
        }
        return (totalMarks / 5.0);
    }

public:
    void getData() {
        cout << "Enter student ID: ";
        cin >> studid;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter marks for 5 subjects: ";
        for (int i = 0; i < 5; ++i) {
            cin >> marks[i];
        }
        percentage = calculatePercentage();
    }

    void showData() {
        cout << "Student ID: " << studid << endl;
        cout << "Student Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }

    float getPercentage() const {
        return percentage;
    }
};

int main() {
    int N;
    cout << "Enter number of students: ";
    cin >> N;

    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cout << "Enter details for student " << i + 1 << endl;
        students[i].getData();
    }

    // Find student with highest percentage
    int highestIndex = 0;
    float highestPercentage = students[0].getPercentage();
    for (int i = 1; i < N; ++i) {
        if (students[i].getPercentage() > highestPercentage) {
            highestIndex = i;
            highestPercentage = students[i].getPercentage();
        }
    }

    // Display details of student with highest percentage
    cout << "\nDetails of student with highest percentage:\n";
    students[highestIndex].showData();

    return 0;
}
