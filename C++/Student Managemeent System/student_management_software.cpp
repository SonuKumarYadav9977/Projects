#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100; // Maximum number of students

// Global student database
int rollNumbers[MAX_STUDENTS];
string names[MAX_STUDENTS];
int marks[MAX_STUDENTS];
int studentCount = 0; // Current number of students

// Function to add a student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student database is full!\n";
        return;
    }
    cout << "Enter Roll Number: ";
    cin >> rollNumbers[studentCount];
    cin.ignore(); // Ignore newline from previous input
    cout << "Enter Name: ";
    getline(cin, names[studentCount]);
    cout << "Enter Marks: ";
    cin >> marks[studentCount];

    studentCount++;
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents() {
    if (studentCount == 0) {
        cout << "No students available!\n";
        return;
    }
    cout << "Student List:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Roll No: " << rollNumbers[i] << ", Name: " << names[i] << ", Marks: " << marks[i] << endl;
    }
}

// Function to search for a student by roll number
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == roll) {
            cout << "Student Found: " << names[i] << ", Marks: " << marks[i] << endl;
            return;
        }
    }
    cout << "Student not found!\n";
}

// Function to delete a student by roll number
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == roll) {
            for (int j = i; j < studentCount - 1; j++) { // Shift elements left
                rollNumbers[j] = rollNumbers[j + 1];
                names[j] = names[j + 1];
                marks[j] = marks[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Function to update student details
void updateStudent() {
    int roll;
    cout << "Enter Roll Number to update: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == roll) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, names[i]);
            cout << "Enter New Marks: ";
            cin >> marks[i];
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
