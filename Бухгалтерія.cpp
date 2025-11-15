#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

class Employee {
private:
    string surname;
    int id;
    double salary;
    double bonusPercent;

public:
    Employee(string s = "", double sal = 0.0, double bonus = 0.0, int i = 0)
        : surname(s), salary(sal), bonusPercent(bonus), id(i) {}

    void input(int number) {
        id = number;
        cout << "Прізвище працівника: ";
        getline(cin, surname);
        cout << "Оклад: ";
        cin >> salary;
        cout << "Премія (%): ";
        cin >> bonusPercent;
        cin.ignore(10000, '\n');
    }

    double getBonus() const { return salary * bonusPercent / 100.0; }
    double getTotal() const { return salary + getBonus(); }
    double getEmployeeTax() const { return getTotal() * 0.205; }
    double getEmployerTax() const { return getTotal() * 0.22; }
    double getNet() const { return getTotal() - getEmployeeTax(); }

    void display() const {
        cout << setw(5) << left << id << " | "
             << setw(15) << left << surname << " | "
             << setw(10) << right << fixed << setprecision(2) << salary << " | "
             << setw(10) << right << getBonus() << " | "
             << setw(10) << right << getTotal() << " | "
             << setw(10) << right << getNet() << endl;
    }
};

class EmployeeManager {
private:
    vector<Employee> employees;

public:
    void inputEmployees() {
        int n;
        cout << "Скільки працівників ви хочете ввести? ";
        cin >> n;
        cin.ignore(10000, '\n');
        employees.resize(n);

        for (int i = 0; i < n; i++) {
            cout << "\nПрацівник " << i + 1 << ":\n";
            employees[i].input(i + 1);
        }
    }

    void displayEmployees() const {
        cout << "\n=== Список працівників ===\n";
        cout << setw(5) << left << "№" << " | "
             << setw(15) << left << "Прізвище" << " | "
             << setw(10) << right << "Оклад" << " | "
             << setw(10) << right << "Сума премії" << " | "
             << setw(10) << right << "ВСЬОГО" << " | "
             << setw(10) << right << "Виплачено" << endl;
        cout << "-----------------------------------------------------------------------------\n";

        for (const auto& emp : employees) {
            emp.display();
        }
    }

    void displayTotal() const {
        double totalGross = 0.0, totalEmployeeTax = 0.0, totalEmployerTax = 0.0, totalNet = 0.0;
        for (const auto& emp : employees) {
            totalGross += emp.getTotal();
            totalEmployeeTax += emp.getEmployeeTax();
            totalEmployerTax += emp.getEmployerTax();
            totalNet += emp.getNet();
        }

        double totalSpent = totalGross + totalEmployerTax;

        cout << fixed << setprecision(2);
        cout << "\n=== Підсумки ===\n";
        cout << setw(25) << left << "Витрачено на заробітну плату:" << setw(10) << right << totalGross << " грн\n";
        cout << setw(25) << left << "Податок з підприємства:" << setw(10) << right << totalEmployerTax << " грн\n";
        cout << setw(25) << left << "Податок з працівника:" << setw(10) << right << totalEmployeeTax << " грн\n";
        cout << setw(25) << left << "Виплачено:" << setw(10) << right << totalNet << " грн\n";
        cout << setw(25) << left << "ВСЬОГО:" << setw(10) << right << totalSpent << " грн\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    EmployeeManager manager;
    manager.inputEmployees();
    manager.displayEmployees();
    manager.displayTotal();

    system("PAUSE");
    return 0;
}
