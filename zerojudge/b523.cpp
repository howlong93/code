#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    set<string> data;

    while (getline(cin, input)) {
        if (data.find(input) != data.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            data.emplace(input);
        }
    }

    return 0;
}
