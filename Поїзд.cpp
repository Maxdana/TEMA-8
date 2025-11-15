#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <windows.h>

using namespace std;

class Train {
public:
    string destination;
    int trainNumber;
    int hour;
    int minute;

    bool isEarlierThan(const Train& other) const {
        if (hour != other.hour)
            return hour < other.hour;
        return minute < other.minute;
    }

    void showTable() const {

        cout << setw(6) << right << trainNumber << " | "
             << setw(20) << left << destination << " | "
             << setw(5) << right << hour << "."
             << (minute < 10 ? "0" : "") << minute << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 5;
    Train trains[N];

    for (int i = 0; i < N; i++) {
        cout << "\nÏÎÒßÃ " << i + 1 << ":\n";

        cout << "Ïóíêò ïğèçíà÷åííÿ: ";
        getline(cin, trains[i].destination);

        cout << "Íîìåğ ïî¿çäà: ";
        cin >> trains[i].trainNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

              while (true) {
            cout << "×àñ â³äïğàâëåííÿ (ãîäèíà.õâèëèíà): ";
            string timeStr;
            getline(cin, timeStr);

            size_t dotPos = timeStr.find('.');
            if (dotPos != string::npos) {
                trains[i].hour = stoi(timeStr.substr(0, dotPos));
                trains[i].minute = stoi(timeStr.substr(dotPos + 1));
            } else {
                trains[i].hour = stoi(timeStr);
                trains[i].minute = 0;
            }

            if (trains[i].hour >= 0 && trains[i].hour <= 23 &&
                trains[i].minute >= 0 && trains[i].minute <= 59) {
                break; // âàë³äíèé ÷àñ
            } else {
                cout << "Íåâ³ğíèé ÷àñ! Ãîäèíè 0-23, õâèëèíè 0-59. Ñïğîáóéòå ùå ğàç.\n";
            }
        }
    }


    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (trains[j].trainNumber > trains[j + 1].trainNumber)
                swap(trains[j], trains[j + 1]);


    cout << "\n=== ÏÎÒßÃÈ, Â²ÄÑÎĞÒÎÂÀÍ² ÇÀ ÍÎÌÅĞÎÌ ===\n";
    cout << setw(6) << right << "¹" << " | "
         << setw(20) << left << "Ïóíêò ïğèçíà÷åííÿ" << " | "
         << "×àñ" << endl;
    cout << string(35, '-') << endl;
    for (int i = 0; i < N; i++) trains[i].showTable();

       int searchNum;
    cout << "\nÂâåä³òü íîìåğ ïî¿çäà äëÿ ïîøóêó: ";
    cin >> searchNum;

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (trains[i].trainNumber == searchNum) {
            cout << "ÏÎÒßÃ ÇÍÀÉÄÅÍÎ:\n";
            cout << setw(6) << right << "¹" << " | "
                 << setw(20) << left << "Ïóíêò ïğèçíà÷åííÿ" << " | "
                 << "×àñ" << endl;
            cout << string(35, '-') << endl;
            trains[i].showTable();
            found = true;
            break;
        }
    }
    if (!found) cout << "Ïî¿çä ç òàêèì íîìåğîì íå çíàéäåíî.\n";


    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (trains[j].destination > trains[j + 1].destination ||
               (trains[j].destination == trains[j + 1].destination &&
                !trains[j].isEarlierThan(trains[j + 1])))
                swap(trains[j], trains[j + 1]);


    cout << "\n=== ÏÎÒßÃÈ, Â²ÄÑÎĞÒÎÂÀÍ² ÇÀ ÏÓÍÊÒÎÌ + ×ÀÑÎÌ ===\n";
    cout << setw(6) << right << "¹" << " | "
         << setw(20) << left << "Ïóíêò ïğèçíà÷åííÿ" << " | "
         << "×àñ" << endl;
    cout << string(35, '-') << endl;
    for (int i = 0; i < N; i++) trains[i].showTable();

    cout << "\nÍàòèñí³òü Enter äëÿ âèõîäó...";
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cin.get();
    return 0;
}
