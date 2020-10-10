#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int i;
        vector<int> data(n);

        for (i = 0; i < n; i++) {
            cin >> data[i];
        }

        sort(data.begin(), data.end(), [](int &a, int &b) {
            if (a % 10 != b % 10) {
                return a % 10 < b % 10;
            } else {
                return a > b;
            }
        });

        for (auto k : data) {
            cout << k << " ";
        }
        cout << "\n";
    }

    return 0;
}
