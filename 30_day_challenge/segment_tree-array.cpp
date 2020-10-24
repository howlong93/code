#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int l, r;
};

vector<Node> segment_tree;

// build segment tree
void build(int x, int L, int R) {
    Node *cur = &segment_tree[x];
    cur->val = 0;
    cur->l = L, cur->r = R;

    if (L == R) {
        return cur;
    }

    int mid = (L + R) / 2;
    build(2 * x, L, mid);
    build(2 * x + 1, mid + 1, R);
    cur->val = max(segment_tree[x * 2].val, segment_tree[x * 2 + 1].val);

    return cur;
}

void add(int x, int pos, int val) {
	Node *cur = &segment_tree[x];
    cur->val += val;

    if (cur->l == cur->r) return;

    if (pos <= cur->lc->r)
        add(2*x, pos, val);
    else
        add(2*x+1, pos, val);
}

// query
int query(int x, int L, int R) {
    Node *cur = &segment_tree[x];
    if (cur->r < L || cur->l > R) return 0;
    if (cur->r <= R && cur->l >= L) return cur->val;

    return query(2 * x, L, R) + query(2 * x + 1, L, R);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int lnth;
    cin >> lnth;

    segment_tree = vector<Node>(4 * lnth);

    // TODO

    return 0;
}
