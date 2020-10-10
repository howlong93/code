#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int data[26][26] = {0};
    char srch, a, b;
    int m, dist;

    cin >> srch >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> dist;
        if (dist > data[a - 'A'][b - 'A']) data[a - 'A'][b - 'A'] = dist;
    }

    for (int p = 0; p < 26; p++) {
        for (int n = 0; n < 26; n++) {
            for (int q = 0; q < 26; q++) {
                if (data[n][p] != 0 && data[p][q] != 0)
                    data[n][q] = max(data[n][q], data[n][p] + data[p][q]);
            }
        }
    }

    dist = 0;
    for (int i = 0; i < 26; i++) dist = max(data[srch - 'A'][i], dist);

    cout << dist << '\n';

    return 0;
}
