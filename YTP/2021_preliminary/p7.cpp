#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second

struct Node {
    int odd = 0, even = 0;
    int l, r;
};

vector<Node> seg;

void build_tree(int x, int L, int R) {
    seg[x].l = L, seg[x].r = R;
    if (L == R) return;

    int mid = (L + R) / 2;
    build_tree(2 * x, L, mid);
    build_tree(2 * x + 1, mid + 1, R);
}

void update(int x, int pos, bool val) {
    if (val)
        seg[x].odd++;
    else
        seg[x].even++;

    if (seg[x].l == seg[x].r) return;

    if (seg[2 * x].r >= pos)
        update(2 * x, pos, val);
    else
        update(2 * x + 1, pos, val);
}

pii query(int x, int L, int R) {
    if (seg[x].r < L || seg[x].l > R) return {0, 0};

    if (seg[x].l >= L && seg[x].r <= R) return {seg[x].odd, seg[x].even};

    pii m, n;
    m = query(2 * x, L, R);
    n = query(2 * x + 1, L, R);
    return {m.ff + n.ff, m.ss + n.ss};
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int lnth;
    cin >> lnth;

    vector<pii> num = vector<pii>(lnth + 1);
    seg = vector<Node>(4 * lnth + 4);
    build_tree(1, 1, lnth);

    for (int i = 1; i <= lnth; i++) cin >> num[i].ff, num[i].ss = i;
    sort(num.begin(), num.end(), [](pii &a, pii &b) { return a.ff < b.ff; });

    long long ans = 0;
    for (int i = 1; i <= lnth; i++) {
        pii L, R;
        L = query(1, 1, num[i].ss - 1);
        R = query(1, num[i].ss + 1, lnth);

        if (num[i].ff % 2)
            ans += 1LL * L.ff * R.ss + 1LL * L.ss * R.ff;
        else
            ans += 1LL * L.ff * R.ff + 1LL * L.ss * R.ss;

        update(1, num[i].ss, num[i].ff % 2);
    }

    cout << ans << '\n';

    return 0;
}
