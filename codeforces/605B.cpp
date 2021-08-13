#include <bits/stdc++.h>

using namespace std;

struct Node {
	int lnth, ch, num;
	int f, t;
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	vector<Node> input (m);
	for (int i = 0; i < m; i++) cin >> input[i].lnth >> input[i].ch, input[i].num = i;
	
	sort(input.begin(), input.end(), [] (Node &a, Node &b) {
		return (a.lnth != b.lnth) ? a.lnth < b.lnth : a.ch > b.ch;
	});
	
	int from = 2, to = 3, iso = 2;
	bool flag = true;
	
	for (int i = 0; i < m; i++) {
		if (input[i].ch)
			input[i].f = 1, input[i].t = iso++;
		else {
			if (to >= iso) {
				flag = false;
				break;
			}
			input[i].f = from, input[i].t = to;
			from++;
			if (from >= to) from = 2, to++;
		}
	}
	
	if (!flag) cout << -1 << '\n';
	else {
		sort (input.begin(), input.end(), [] (Node &a, Node &b) {
			return a.num < b.num;
		});
		for (auto k: input) cout << k.f << ' ' << k.t << '\n';
	}
	
	return 0;
}
			
