#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
    string name, profession, address, pan;
    int age;
    double salary, tax;

public:
    // Default constructor
    Employee() 
        : name("Unknown"), age(0), profession("Unknown"), salary(0.0), address("Unknown"), pan("Unknown"), tax(0.0) {}

    // Parameterized constructor
    Employee(string n, int a, string p, double s, string addr, string panNo)
        : name(n), age(a), profession(p), salary(s), address(addr), pan(panNo) {
        tax = calculateTax();
    }

    double calculateTax() {
        if (salary <= 250000) {
            return 0.0;
        } else if (salary <= 500000) {
            return (salary - 250000) * 0.05;
        } else {
            return (salary - 500000) * 0.2 + (250000 * 0.05); // add tax from slab 2 also
        }
    }

    void printTax() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Profession: " << profession << endl;
        cout << "Salary: " << fixed << setprecision(2) << salary << endl;
        cout << "PAN: " << pan << endl;
        cout << "Tax: " << fixed << setprecision(2) << tax << endl;
    }
};

int main() {
    Employee emp1("Paul Sharma", 30, "Software Engineer", 750000, "Mumbai, India", "ABCDE1234F");
    emp1.printTax();
    return 0;
}
