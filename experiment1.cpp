#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];
    float total;
    float percentage;
    string result;

public:
    void acceptDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // Clears the input buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    void calculateResult() {
        total = 0;
        bool hasFailedSubject = false;

        for (int i = 0; i < 3; i++) {
            total += marks[i];
            // Optional: Check if student failed an individual subject (e.g., scoring below 40)
            if (marks[i] < 40) {
                hasFailedSubject = true;
            }
        }

        percentage = total / 3.0f;

        // Determine Pass/Fail status based on total percentage or individual subjects
        if (percentage >= 40 && !hasFailedSubject) {
            result = "Passed";
        } else {
            result = "Failed";
        }
    }

    void displayDetails() {
        cout << "\n----- Student Report Card -----\n";
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Name        : " << name << endl;
        cout << "Total Marks : " << total << "/300" << endl;
        cout << "Percentage  : " << percentage << "%" << endl;
        cout << "Status      : " << result << endl;
    }
};

int main() {
    Student s;
    s.acceptDetails();
    s.calculateResult();
    s.displayDetails();
    return 0;
}
