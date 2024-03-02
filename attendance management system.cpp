#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Class for a person's information
class Person {
    string name;
    int regNo;
    int numClasses;
    int attendance;

public:
    // Constructor
    Person(string name, int regNo, int numClasses, int attendance)
        : name(name), regNo(regNo), numClasses(numClasses), attendance(attendance) {}

    // Getters
    string getName() const {
        return name;
    }

    int getRegNo() const {
        return regNo;
    }

    int getNumClasses() const {
        return numClasses;
    }

    int getAttendance() const {
        return attendance;
    }

    // Update attendance
    void updateAttendance(bool present) {
        numClasses++;
        if (present) {
            attendance++;
        }
    }

    // Calculate attendance percentage
    double calculateAttendancePercentage() const {
        return (static_cast<double>(attendance) / numClasses) * 100;
    }
};

int main() {
    // Declare an array of 10 persons
    Person persons[10] = {
        Person("Alice", 1001, 20, 18),
        Person("Bob", 1002, 19, 16),
        Person("Charlie", 1003, 20, 19),
        Person("Dave", 1004, 20, 17),
        Person("Eve", 1005, 18, 14),
        Person("Frank", 1006, 19, 17),
        Person("Grace", 1007, 20, 17),
        Person("Harry", 1008, 19, 15),
        Person("Ivy", 1009, 20, 19),
        Person("Jack", 1010, 20, 18)
    };

    // Display the persons' information
    cout << "Name\tReg No\tClasses\tClasses Attended\tAttendance(%)\n";
    cout << "-----------------------------------------------------\n";
    for (int i = 0; i < 10; i++) {
        double percentage = persons[i].calculateAttendancePercentage();
        cout << persons[i].getName() << "\t" << persons[i].getRegNo() << "\t" << persons[i].getNumClasses() << "\t" << persons[i].getAttendance() << "\t\t" << fixed << setprecision(2) << percentage << endl;
    }

    // Ask for input to update today's attendance
    cout << "\nEnter 'p' for present and 'a' for absent:\n";
    for (int i = 0; i < 10; i++) {
        char present;
        cout << persons[i].getName() << ":\t";
        cin >> present;
        bool isPresent = (present == 'p');
        persons[i].updateAttendance(isPresent);
    }

    // Display the updated attendance
    cout << "\nUpdated attendance:\n";
    cout << "Name\tReg No\tClasses\tClasses Attended\tAttendance(%)\n";
    cout << "-----------------------------------------------------\n";
    for (int i = 0; i < 10; i++) {
        double percentage = persons[i].calculateAttendancePercentage();
        cout << persons[i].getName() << "\t" << persons[i].getRegNo() << "\t" << persons[i].getNumClasses() << "\t" << persons[i].getAttendance() << "\t\t" << fixed << setprecision(2) << percentage << endl;
    }

    return 0;
}
