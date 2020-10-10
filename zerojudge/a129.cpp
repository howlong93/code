#include <bits/stdc++.h>

using namespace std;

struct edgetype {
    int a, b;
    int dist;
};

int find_root(int, vector<int> &);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        long long int ans = 0;
        vector<edgetype> edge(m);
        vector<int> par(n);
        for (int i = 0; i < n; i++) par[i] = i;
        for (int i = 0; i < m; i++)
            cin >> edge[i].a >> edge[i].b >> edge[i].dist;

        sort(edge.begin(), edge.end(),
             [](edgetype &x, edgetype &y) { return x.dist < y.dist; });

        for (int i = 0; i < m; i++) {
            int para = find_root(edge[i].a, par),
                parb = find_root(edge[i].b, par);

            if (para != parb) {
                ans += edge[i].dist;
                par[para] = par[parb];
            }
        }

        int keep = -1;
        for (int i = 0; i < n; i++) {
            if (keep < 0)
                keep = find_root(par[i], par);
            else if (keep != find_root(par[i], par)) {
                ans = -1;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

int find_root(int x, vector<int> &par) {
    if (par[x] == x) return x;
    return par[x] = find_root(par[x], par);
}
