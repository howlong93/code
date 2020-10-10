#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    while (cin >> input) {
        int check[26] = {0}, odd = 0;
        for (auto k : input) {
            if (isupper(k) || islower(k)) {
                k = tolower(k);
                check[k - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (check[i] % 2 == 1) odd++;
        }

        if (odd < 2)
            cout << "yes !\n";
        else
            cout << "no...\n";
    }

    return 0;
}
