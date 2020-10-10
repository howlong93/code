#include <bits/stdc++.h>

using namespace std;

int main() {
    bool cur;
    int n, i;
    while (cin >> n) {
        vector<bool> line(n), col(n);
        vector<int> a[2];
        for (i = 0; i < n * n; i++) {
            cin >> cur;
            line[i / n] = line[i / n] ^ cur;
            col[i % n] = col[i % n] ^ cur;
        }

        for (i = 0; i < n; i++)
            if (line[i]) a[0].emplace_back(i + 1);
        for (i = 0; i < n; i++)
            if (col[i]) a[1].emplace_back(i + 1);

        if (a[0].size() == 0 && a[1].size() == 0)
            cout << "OK\n";
        else if (a[0].size() == 1 && a[1].size() == 1)
            cout << "Change bit (" << a[0][0] << "," << a[1][0] << ")\n";
        else
            cout << "Corrupt\n";
    }

    return 0;
}
