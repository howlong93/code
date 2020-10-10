#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    while (cin >> n) {
        string data[n], keep, cur;

        for (i = 0; i < n; i++) cin >> data[i];

        do {
            cur = "";
            for (auto k : data) cur += k;
            keep = max(cur, keep);
        } while (next_permutation(data, data + n));

        cout << keep << "\n";
    }

    return 0;
}
