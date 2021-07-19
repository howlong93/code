#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int tot_size = 52*52*52;

int gint (char a) {
	return (a >= 'A' && a <= 'Z') ? a-'A' : a-'a'+26;
}

int enc (char a, char b, char c) {
	return 52*52*gint(a) + 52 * gint(b) + gint(c);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<vector<int>> graph = vector<vector<int>> (tot_size);
	vector<pii> edge = vector<pii> (n);
	vector<int> cnt = vector<int> (tot_size, 0);
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		int sz = tmp.size();
		edge[i] = make_pair(enc(tmp[0], tmp[1], tmp[2]), enc(tmp[sz-3], tmp[sz-2], tmp[sz-1]));
		cnt[edge[i].first]++;
		graph[edge[i].second].push_back (edge[i].first);
	}
	
	vector<int> ans = vector<int> (tot_size, -1);
	queue<int> que;
	for (int i = 0; i < tot_size; i++) {
		if (cnt[i] == 0) ans[i] = 0, que.push(i);
	}
	
	while (!que.empty()) {
		int tmp = que.front();
		que.pop();
		for (int k: graph[tmp]) {
			if (ans[k] == -1) {
				cnt[k]--;
				if (ans[tmp] == 0) ans[k] = 1, que.push(k);
				else if (cnt[k] == 0) ans[k] = 0, que.push(k);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (ans[edge[i].second] == -1) cout << "Draw\n";
		else if (ans[edge[i].second] == 0) cout << "Takahashi\n";
		else if (ans[edge[i].second] == 1) cout << "Aoki\n";
	}
	
	return 0;
}
