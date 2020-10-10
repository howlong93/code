#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        int i = 0;
        string input;
        map<string, int> data;

        while (n--) {
            cin >> input;
            if (data.find(input) == data.end()) {
                data[input] = ++i;
                cout << "New! " << i << "\n";
            } else {
                cout << "Old! " << data[input] << "\n";
            }
        }
    }

    return 0;
}
