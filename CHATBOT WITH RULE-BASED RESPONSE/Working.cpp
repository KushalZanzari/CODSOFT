#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    double gpa;

    // Information we have
    Student(string n, int roll, double grade) : name(move(n)), rollNumber(roll), gpa(grade) {}

    // student information
    void displayInfo() const {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nGPA: " << gpa << endl;
    }

    //  student failed condition
    bool hasFailed() const {
        return gpa < 5.0;
    }
};

// adding a new student 
void addStudent(vector<Student> &students, vector<Student> &failStudents) {
    string name;
    int rollNumber;
    double gpa;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter roll number: ";
    cin >> rollNumber;

    cout << "Enter GPA: ";
    cin >> gpa;

    students.emplace_back(name, rollNumber, gpa);
    cout << "Student added successfully!\n";

    // Check student has failed
    if (students.back().hasFailed()) {
        cout << "Warning: This student has failed.\n";
        failStudents.push_back(students.back());
    }
}

//  display all students' information
void displayAllStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students to display.\n";
    } else {
        cout << "\nStudent Information:\n";
        for (const auto &student : students) {
            student.displayInfo();

            // Check if the student has failed
            if (student.hasFailed()) {
                cout << "Result: Fail\n";
            } else {
                cout << "Result: Pass\n";
            }

            cout << "---------------------\n";
        }
    }
}

// display the list of failed students
void displayFailStudents(const vector<Student> &failStudents) {
    if (failStudents.empty()) {
        cout << "No students have failed.\n";
    } else {
        cout << "\nList of Fail Students:\n";
        for (const auto &student : failStudents) {
            student.displayInfo();
            cout << "---------------------\n";
        }
    }
}

int main() {
    vector<Student> students;
    vector<Student> failStudents;

    while (true) {
        cout << "\n\t\tMenu:\n";
        cout << "\t1. Add Student\n";
        cout << "\t2. Display All Students\n";
        cout << "\t3. Display Fail Students\n";
        cout << "\t4. Quit\n";
        cout << "\t\n\nEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();  // Clear newline from the buffer
                addStudent(students, failStudents);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                displayFailStudents(failStudents);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
