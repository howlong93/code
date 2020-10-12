#include <iostream>

using namespace std;

int main() {
    string input;

    while (cin >> input) {
        if (input == "-1") break;
        int cnt = 0;
        bool alpha[26] = {false};

        for (auto k : input) {
            alpha[k - 'A'] = true;
        }

        for (int i = 0; i < 26; i++)
            if (alpha[i] == true) cnt++;

        cout << cnt << "\n";
    }

    return 0;
}
