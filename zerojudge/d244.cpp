#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> data;
    int n;
    while (cin >> n) data[n]++;

    for (auto k : data) {
        if (k.second % 3 != 0) {
            cout << k.first << "\n";
            break;
        }
    }

    return 0;
}
