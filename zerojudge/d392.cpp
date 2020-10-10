#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input;
    cin.clear();

    while (getline(cin, input)) {
        long int keep, sum = 0;
        stringstream ss;
        ss << input;

        while (ss >> keep) sum += keep;
        cout << sum << "\n";
    }

    return 0;
}
