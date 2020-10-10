#include <bits/stdc++.h>

using namespace std;

struct Etype {
    int a, b;
    int dist;
};

vector<int> par;

int find_root(int x) {
    if (par[x] == x) return x;
    return par[x] = find_root(par[x]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<Etype> edge(m);
    par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < m; i++) cin >> edge[i].a >> edge[i].b >> edge[i].dist;

    sort(edge.begin(), edge.end(),
         [](Etype &x, Etype &y) { return x.dist < y.dist; });

    for (int i = 0; i < m; i++) {
        int para = find_root(edge[i].a), parb = find_root(edge[i].b);
        if (para != parb) {
            ans += edge[i].dist;
            par[para] = par[parb];
        }
    }

    cout << ans << '\n';
}
