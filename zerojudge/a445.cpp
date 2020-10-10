#include <bits/stdc++.h>

using namespace std;

vector<int> sz, par;

int find_root(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = find_root(par[x]);
}

void merge(int x, int y) {
    if (sz[x] > sz[y]) {
        sz[x] += sz[y];
        par[y] = par[x];
    } else {
        par[x] = par[y];
        sz[y] += sz[x];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int man, rel, quer, a, b;
    cin >> man >> rel >> quer;

    par.resize(man + 1);
    for (int i = 0; i <= man; i++) par[i] = i;

    sz.resize(man + 1, 1);
    fill(sz.begin(), sz.end(), 1);

    for (int i = 0; i < rel; i++) {
        cin >> a >> b;
        int para = find_root(a), parb = find_root(b);
        if (para != parb) merge(para, parb);
    }

    for (int i = 0; i < quer; i++) {
        cin >> a >> b;
        if (find_root(a) == find_root(b))
            cout << ":)\n";
        else
            cout << ":(\n";
    }

    return 0;
}
