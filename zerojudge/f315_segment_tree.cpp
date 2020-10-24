#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int l, r;

    Node *lc = nullptr, *rc = nullptr;
};

Node *build(int L, int R) {
    Node *cur = new Node;

    cur->val = 0;
    cur->l = L, cur->r = R;

    if (L == R) return cur;

    int mid = (L + R) / 2;
    cur->lc = build(L, mid);
    cur->rc = build(mid + 1, R);

    return cur;
}

void add(Node *cur, int pos, int val) {
    cur->val += val;

    if (cur->l == cur->r) return;

    if (pos <= cur->lc->r)
        add(cur->lc, pos, val);
    else
        add(cur->rc, pos, val);
}

int sum(Node *cur, int L, int R) {
    if (cur->r < L || cur->l > R) return 0;
    if (cur->r <= R && cur->l >= L) return cur->val;

    return sum(cur->lc, L, R) + sum(cur->rc, L, R);
}

int main() {
    long long int ans = 0;
    int lnth;
    cin >> lnth;

    Node *root = build(0, 2 * lnth - 1);

    vector<int> num(2 * lnth);
    vector<vector<int>> pos(lnth + 1);
    for (int i = 0; i < 2 * lnth; i++) cin >> num[i];
    for (int i = 0; i < 2 * lnth; i++) {
        pos[num[i]].push_back(i);
    }

    for (int i = 1; i <= lnth; i++) {
        ans += sum(root, pos[i][0], pos[i][1]);
        add(root, pos[i][0], 1);
        add(root, pos[i][1], 1);
    }

    cout << ans << '\n';

    return 0;
}
