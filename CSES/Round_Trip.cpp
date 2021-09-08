#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> vis, track;
bool flag = false;

void output () {
    int tmp = track[track.size()-1];
    for (int i = track.size()-2; i >= 0; i--) {
        if (track[i] == tmp) {
            tmp = i;
            break;
        }
	}

	cout << track.size()-tmp << '\n';                                       
    for (int i = tmp; i < track.size(); i++) cout << track[i] << ' ';                                                                                                    
    cout << '\n';
}

void dfs (int x, int lnth, int par) {
	track.emplace_back (x);
	vis[x] = lnth;
	for (auto k: graph[x]) {
		if (k != par && vis[k] < vis[x]) {
			if (vis[k] == -1) dfs (k, lnth+1, x);
			else {
				track.emplace_back (k);
				flag = true;
				output();
				return;
			}
		}
		if (flag) break;
	}
	track.pop_back();
}
	
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	graph = vector<vector<int>> (n+1);
	vis = vector<int> (n+1, -1);

	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		graph[p].emplace_back (q);
		graph[q].emplace_back (p);
	}

	for (int i = 1; i <= n; i++) {
		track.clear();
		if (vis[i] == -1) dfs (i, 0, 0);
		if (flag) break;
	}

	if (!flag) cout << "IMPOSSIBLE\n";
	return 0;
}
