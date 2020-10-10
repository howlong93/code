#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> par[], vector<bool> &vis, int i) {
    vis[i] = true;
    for (auto k : par[i]) {
        if (!vis[k]) dfs(par, vis, k);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, kk = 1;

    while (cin >> n >> m && n != 0) {
        vector<int> par[n + 1];
        vector<bool> vis(n + 1, false);

        int a, b, cnt = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            par[a].emplace_back(b);
            par[b].emplace_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(par, vis, i);
                cnt++;
            }
        }

        cout << "Case " << kk++ << ": " << cnt << '\n';
    }

    return 0;
}
