#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    while (cin >> input) {
        for (unsigned int i = 0; i < input.size() - 1; i++) {
            cout << abs(input[i] - input[i + 1]);
        }
        cout << "\n";
    }

    return 0;
}
