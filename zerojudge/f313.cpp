#include <bits/stdc++.h>

using namespace std;

int row, col, num, day, kmax = INT_MIN, kmin = INT_MAX;
vector<vector<int>> city, keep;

int fnd(int x, int y) {
    if (x >= row || y >= col || y < 0 || x < 0) return 0;
    return keep[x][y];
}

void build_k() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (city[i][j] == -1)
                keep[i][j] = 0;
            else {
                keep[i][j] = city[i][j] / num;
            }
        }
    }
}
int cnt_city(int x, int y) {
    int cnt = 0;
    if (x + 1 < row && city[x + 1][y] != -1) cnt++;
    if (x - 1 >= 0 && city[x - 1][y] != -1) cnt++;
    if (y + 1 < col && city[x][y + 1] != -1) cnt++;
    if (y - 1 >= 0 && city[x][y - 1] != -1) cnt++;

    return cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> row >> col >> num >> day;

    city = vector<vector<int>>(row, vector<int>(col));
    keep = vector<vector<int>>(row, vector<int>(col));

    // input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> city[i][j];
        }
    }

    for (int i = 0; i < day; i++) {
        build_k();

        for (int m = 0; m < row; m++) {
            for (int n = 0; n < col; n++) {
                if (city[m][n] != -1) {
                    city[m][n] += fnd(m, n + 1) + fnd(m, n - 1) +
                                  fnd(m + 1, n) + fnd(m - 1, n);
                    city[m][n] -= keep[m][n] * cnt_city(m, n);
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (city[i][j] != -1) kmax = max(kmax, city[i][j]);
            if (city[i][j] != -1) kmin = min(kmin, city[i][j]);
        }
    }

    cout << kmin << '\n' << kmax << '\n';

    return 0;
}
