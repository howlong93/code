#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	int l, r;

	int tag_val = 0;
};

Node seg[1200000];

void push (int x) {
	if (seg[x].tag_val == 0) return;
	if (seg[x].l == seg[x].r) return;

	int val = seg[x].tag_val;
	seg[2*x].val = seg[2*x].tag_val = val;
	seg[2*x+1].val = seg[2*x+1].tag_val = val;
	seg[x].tag_val = 0;
}

void build (int x, int L, int R) {
	seg[x].val = 0;

	seg[x].l = L, seg[x].r = R;
	if (L == R) return;

	int mid = (L+R)/2;
	build (2*x, L, mid);
	build (2*x+1, mid+1, R);
}

void update (int x, int L, int R, int val) {
	if (L > seg[x].r || R < seg[x].l) return;
	push (x);
	if (L <= seg[x].l && R >= seg[x].r) {
		seg[x].tag_val = val;
		seg[x].val = val;
		return;
	}

	update (2*x, L, R, val);
	update (2*x+1, L, R, val);
}

void dfs (int x) {
	push (x);
	if (seg[x].l == seg[x].r) {
		cout << seg[x].val << ' ';
		return;
	}

	dfs (2*x);
	dfs (2*x+1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int lnth, amt;
	cin >> lnth >> amt;
	vector<array<int, 3>> fight (amt);
	build (1, 1, lnth);

	for (int i = 0; i < amt; i++) 
		cin >> fight[i][0] >> fight[i][1] >> fight[i][2];

	for (int i = amt-1; i >= 0; i--) {
		if (fight[i][2] != fight[i][0])
			update (1, fight[i][0], fight[i][2]-1, fight[i][2]);
		if (fight[i][2] != fight[i][1])
			update (1, fight[i][2]+1, fight[i][1], fight[i][2]);
	}

	dfs (1);

	return 0;
}
