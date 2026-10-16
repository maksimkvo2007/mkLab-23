#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

int main_menu() {
    int ch = 0;
    while (ch < 1 || ch > 4) {
        cout << "\n*** GOAT MANAGER 3001 ***\n";
        cout << "[1] Add a goat\n";
        cout << "[2] Delete a goat\n";
        cout << "[3] List goats\n";
        cout << "[4] Quit\n";
        cout << "Choice --> ";
        cin >> ch;
    }
    return ch;
}
