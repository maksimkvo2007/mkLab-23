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

void display_trip(const list<Goat>& trip) {
    if (trip.empty()) {
        cout << "Trip is empty.\n";
        return;
    }
    int idx = 1;
    for (auto it = trip.begin(); it != trip.end(); ++it) {
        cout << "[" << idx++ << "] ";
        it->print();
        cout << endl;
    }
}

void add_goat(list<Goat>& trip, string names[], int ns, string colors[], int cs) {
    string n = names[rand() % ns];
    string c = colors[rand() % cs];
    int a = rand() % (MAX_AGE + 1);

    Goat g(n, a, c);
    trip.push_back(g);
    cout << "Added: ";
    g.print();
    cout << endl;
}


int main() {
    srand(time(0));

    string names[] = {"Vida", "Nola", "Todd", "Faye", "Lena", "Owen", "Kyle", "Vern"}; // Preset arrays for random selection
    string colors[] = {"Red", "Gold", "Green", "Silver", "Teal", "Magenta", "Olive", "Blue"};
    int name_sz = 8;
    int color_sz = 8;

}