#include "Menu.h"
#include <chrono>
Menu::Menu() = default;

void Menu::start(vector<Van> vans, vector<Parcel> parcels) {
    unsigned short answer;
    bool error = true;

    do {
        cout <<
             "-----------------------------" << endl <<
             "|        Deliveries         |" << endl <<
             "|Number of workers:      1  |" << endl <<
             "|Company's profit:       2  |" << endl <<
             "|Express deliveries:     3  |" << endl <<
             "|Exit:                   0  |" << endl <<
             "-----------------------------" << endl;
        cin >> answer;
        if (cin.eof()) {
            exit(0);
        }
        if (!cin.good()) {
            cout << "Sadly that's not an option. Please choose another one." << std::endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            continue;
        }
        switch (answer) {
            case 1: {
                chrono::high_resolution_clock::time_point start1, end1;
                Scenario1 scenario1 = Scenario1(vans, parcels);
                start1 = chrono::high_resolution_clock::now();
                scenario1.minOfVans();
                end1 = chrono::high_resolution_clock::now();
                cout << '\n' << "total of " << chrono::duration_cast<chrono::microseconds>(end1-start1).count() << " elapsed microseconds";
                error = false;
                break;
            }
            case 2: {
                chrono::high_resolution_clock::time_point start2, end2;
                Scenario2 s2 = Scenario2(vans, parcels);
                start2 = chrono::high_resolution_clock::now();
                s2.start();
                s2.show();
                end2 = chrono::high_resolution_clock::now();
                cout << '\n' << "total of " << chrono::duration_cast<chrono::microseconds>(end2-start2).count() << " elapsed microseconds";
                error = false;
                break;
            }
            case 3: {
                chrono::high_resolution_clock::time_point start3, end3;

                Scenario3 scenario3;
                start3 = chrono::high_resolution_clock::now();
                scenario3.getMeanTime();
                end3 = chrono::high_resolution_clock::now();

                cout << '\n' << "total of " << chrono::duration_cast<std::chrono::microseconds>(end3-start3).count() << " elapsed microseconds";
                error = false;
                break;
            }
            case 0:
                exit(0);
            default:
                cout << "Sadly that's not an option. Please choose another one." << endl;
        }
    } while (error);
}
