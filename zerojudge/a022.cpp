#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    while (cin >> input) {
        string back = input;
        reverse(input.begin(), input.end());

        if (input == back)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
