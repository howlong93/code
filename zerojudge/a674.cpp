#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int pnt_amt, ed_amt, q_amt, lllll = 1;

    cin >> pnt_amt >> ed_amt >> q_amt;
    while (!(pnt_amt == 0 && ed_amt == 0 && q_amt == 0)) {
        cout << "Case #" << lllll++ << '\n';
        int a, b, dist;
        vector<vector<int>> pnt(pnt_amt + 1);

        for (int i = 1; i <= pnt_amt; i++) {
            pnt[i].resize(pnt_amt + 1);
            fill(pnt[i].begin(), pnt[i].end(), INT_MAX);
        }

        for (int i = 0; i < ed_amt; i++) {
            cin >> a >> b >> dist;
            pnt[a][b] = dist;
            pnt[b][a] = dist;
        }

        for (int k = 1; k <= pnt_amt; k++) {
            for (int i = 1; i <= pnt_amt; i++) {
                for (int j = 1; j <= pnt_amt; j++) {
                    pnt[i][j] = min(pnt[i][j], max(pnt[i][k], pnt[k][j]));
                }
            }
        }

        for (int i = 0; i < q_amt; i++) {
            cin >> a >> b;
            if (pnt[a][b] == INT_MAX)
                cout << "no path\n";
            else
                cout << pnt[a][b] << '\n';
        }
        cout << '\n';

        cin >> pnt_amt >> ed_amt >> q_amt;
    }

    return 0;
}
