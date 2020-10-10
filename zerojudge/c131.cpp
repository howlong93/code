#include <bits/stdc++.h>

using namespace std;

map<int, int> par;

int find_root(int x) {
    if (par[x] == 0) {
        par[x] = x;
        return x;
    } else if (par[x] == x)
        return x;
    return par[x] = find_root(par[x]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, casenum = 1;
    bool flag = true;
    cin >> a >> b;
    while (a >= 0 && b >= 0) {
        if (a == 0 && b == 0) {
            int keep = -1;
            for (auto k : par) {
                if (keep < 0)
                    keep = find_root(k.first);
                else if (keep != find_root(k.second)) {
                    flag = false;
                }
            }
            cout << "Case " << casenum++ << " is " << (flag ? "" : "not ")
                 << "a tree.\n";
            par.clear();
            flag = true;
        } else {
            if (a == b) flag = false;
            if (par[b] != 0 && par[b] != b)
                flag = false;
            else {
                int keep = find_root(a);
                if (keep == b) flag = false;
                par[b] = keep;
            }
        }
        cin >> a >> b;
    }

    return 0;
}
