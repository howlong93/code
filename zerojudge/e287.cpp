#include <bits/stdc++.h>

using namespace std;

long long int ans = 0;
vector<vector<int>> n_map;
vector<vector<bool>> vis;

pair<int, int> check(int x, int y) {
    pair<int, int> m;
    if (n_map[x + 1][y] != INT_MAX && !vis[x + 1][y])
        m.first = x + 1, m.second = y;
    if (n_map[x - 1][y] != INT_MAX && !vis[x - 1][y] &&
        n_map[m.first][m.second] > n_map[x - 1][y])
        m.first = x - 1, m.second = y;
    if (n_map[x][y + 1] != INT_MAX && !vis[x][y + 1] &&
        n_map[m.first][m.second] > n_map[x][y + 1])
        m.first = x, m.second = y + 1;
    if (n_map[x][y - 1] != INT_MAX && !vis[x][y - 1] &&
        n_map[m.first][m.second] > n_map[x][y - 1])
        m.first = x, m.second = y - 1;

    if (m.first == m.second && m.first == 0)
        return make_pair(-1, -1);
    else
        return m;
}

void dfs(int x, int y) {
    ans += n_map[x][y];
    vis[x][y] = true;
    pair<int, int> keep = check(x, y);
    if (keep.first == -1) return;
    dfs(keep.first, keep.second);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int line, col;
    int stx = 0, sty = 0;
    cin >> line >> col;

    n_map = vector<vector<int>>(line + 2, vector<int>(col + 2, INT_MAX));
    vis = vector<vector<bool>>(line + 2, vector<bool>(col + 2, false));

    for (int i = 1; i <= line; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> n_map[i][j];
            if (n_map[stx][sty] > n_map[i][j]) stx = i, sty = j;
        }
    }

    dfs(stx, sty);
    cout << ans << '\n';
}
