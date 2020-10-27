#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	int l, r;

	Node *lc = nullptr, *rc = nullptr;
};

Node *build (int L, int R, bool flag) {
	Node *cur = new Node;

	cur -> l  = L, cur -> r = R;
	if (L == R) {
		cin >> cur -> val;
		return cur;
	}

	int mid = (L+R)/2;
	cur -> lc = build (L, mid, flag ^ 1);
	cur -> rc = build (mid+1, R, flag ^ 1);

	if (flag) cur -> val = cur -> lc -> val | cur -> rc -> val;
	else cur -> val = cur -> lc -> val ^ cur -> rc -> val;

	return cur;
}

int update (Node *cur, int pos, int val, bool flag) {
	if (cur -> l == cur -> r) return cur -> val = val;

	if (pos <= cur -> lc -> r) {
		int keep = update (cur -> lc, pos, val, flag ^ 1);
		if (flag) cur -> val = cur -> rc -> val | keep;
		else cur -> val = cur -> rc -> val ^ keep;
	}
	else {
		int keep = update (cur -> rc, pos, val, flag ^ 1);
		if (flag) cur -> val = cur -> lc -> val | keep;
		else cur -> val = cur -> lc -> val ^ keep;
	}

	return cur -> val;
}

long long int lnth, qamt;
long long int tln;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> lnth >> qamt;
	tln = 1 << lnth;

	Node *root = build (1, tln, lnth%2);

	for (int i = 0; i < qamt; i++) {
		int pos, val;
		cin >> pos >> val;
		update (root, pos, val, lnth%2);
		cout << root -> val << '\n';
	}

	return 0;
}
