#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int l, r;
};

vector<Node> segment_tree;

void build(int x, int L, int R) {
    Node *cur = &segment_tree[x];
    cur->val = 0;
    cur->l = L, cur->r = R;

    if (L == R) {
        cin >> cur->val;
        return cur;
    }

    int mid = (L + R) / 2;
    build(2 * x, L, mid);
    build(2 * x + 1, mid + 1, R);
    cur->val = max(segment_tree[x * 2].val, segment_tree[x * 2 + 1].val);

    return cur;
}

int query(Node *cur, int L, int R) {
    if (cur->r < L || cur->l > R) return INT_MIN;
    if (cur->r <= R && cur->l >= L) return cur->val;

    return max(query(cur->lc, L, R), query(cur->rc, L, R));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int lnth, val, qamt;
    cin >> lnth;

    Node *root = build(1, lnth);

    cin >> qamt;
    for (int i = 0; i < qamt; i++) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);

        cout << query(root, l, r) << '\n';
    }

    return 0;
}
