#include <iostream>

using namespace std;

int main() {
    int amount;
    string input;

    cin >> amount;
    getline(cin, input);
    while (amount--) {
        int cnt[26] = {0}, save = 0, i = 0;
        getline(cin, input);
        for (auto k : input) {
            if (isalpha(k)) {
                cnt[tolower(k) - 'a']++;
            }
        }

        for (i = 0; i < 26; i++) {
            save = max(cnt[i], save);
        }
        for (i = 0; i < 26; i++) {
            if (cnt[i] == save) cout << char('a' + i);
        }
        cout << "\n";
    }

    return 0;
}
