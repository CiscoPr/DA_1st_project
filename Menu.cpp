#include "Menu.h"

Menu::Menu() = default;

void Menu::start() {
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
            case 1:

                error = false;
                break;
            case 2:

                error = false;
                break;
            case 3:

                error = false;
                break;
            case 0:
                exit(0);
            default:
                cout << "Sadly that's not an option. Please choose another one." << endl;
        }
    } while (error);
}