#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    unsigned int m, n, i, cnt = 0;
    cin >> m >> n;

    string keep;

    map<string, int> data;
    vector<string> saving(n);

    for (i = 0; i < n; i++) {
        cin >> keep;
        saving[i] = keep;

        data[keep]++;
        if (data.size() == m) cnt++;

        if (i >= m - 1) {
            if (data[saving[i - m + 1]] == 1)
                data.erase(saving[i - m + 1]);
            else
                data[saving[i - m + 1]]--;
        }
    }

    cout << cnt << "\n";

    return 0;
}
