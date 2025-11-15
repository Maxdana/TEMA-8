#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Student {
public:
    string surnameInitials;
    int groupNumber;
    int grades[5];

    double getAverage() const {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += grades[i];
        return sum / 5.0;
    }

    bool onlyGoodGrades() const {
        for (int i = 0; i < 5; i++)
            if (grades[i] < 4)
                return false;
        return true;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];

    for (int i = 0; i < N; i++) {
        cout << "\nСтудент " << i + 1 << ":\n";
        cout << "Прізвище та ініціали: ";
        cin.ignore();
        getline(cin, students[i].surnameInitials);

        cout << "Номер групи: ";
        cin >> students[i].groupNumber;

        cout << "Введіть 5 оцінок: ";
        for (int j = 0; j < 5; j++)
            cin >> students[i].grades[j];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (students[j].getAverage() > students[j + 1].getAverage()) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "\n=== Впорядкування за середнім балом ===\n";
    for (int i = 0; i < N; i++) {
        cout << students[i].surnameInitials
            << ", група: " << students[i].groupNumber
            << ", середній бал: " << students[i].getAverage() << endl;
    }

    cout << "\n=== Студенти з оцінками тільки 4 або 5 ===\n";
    for (int i = 0; i < N; i++) {
        if (students[i].onlyGoodGrades()) {
            cout << students[i].surnameInitials
                << " — група " << students[i].groupNumber << endl;
        }
    }

    delete[] students;
    return 0;
}
