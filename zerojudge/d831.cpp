#include <bits/stdc++.h>

using namespace std;

int mxsz;
vector<int> sz, par;

int find_root(int x) {
    if (par[x] == x) return x;
    return par[x] = find_root(par[x]);
}

void merge(int x, int y) {
    if (sz[x] > sz[y]) {
        par[y] = par[x];
        sz[x] += sz[y];
    } else {
        par[x] = par[y];
        sz[y] += sz[x];
    }

    mxsz = max({mxsz, sz[y], sz[x]});
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        mxsz = 1;
        sz.resize(n);
        fill(sz.begin(), sz.end(), 1);
        par.resize(n);
        int a, b;
        for (int i = 0; i < n; i++) par[i] = i;

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            a = find_root(a);
            b = find_root(b);
            if (a != b) merge(a, b);
        }

        cout << mxsz << '\n';
    }

    return 0;
}
