#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Goat.h"

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

int main() {
    srand(time(0));

    string names[] = {"Vida", "Nola", "Todd", "Faye", "Lena", "Owen", "Kyle", "Vern"}; // Preset arrays for random selection
    string colors[] = {"Red", "Gold", "Green", "Silver", "Teal", "Magenta", "Olive", "Blue"};
    int name_sz = 8;
    int color_sz = 8;

}