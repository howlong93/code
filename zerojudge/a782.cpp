#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string input;

    cin.clear();
    do {
        stringstream ss;
        string keep;
        getline(cin, input);
        if (input == "END") break;
        ss << input;
        while (ss >> keep) {
            cout << char(toupper(keep[0]));
        }
        cout << " " << keep << "\n";
    } while (input != "END");

    return 0;
}
