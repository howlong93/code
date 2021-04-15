#include <bits/stdc++.h>

using namespace std;

long long int INF = 1LL << 60;
struct Dinic {
	struct Edge {
		int u, v;
		long long cap, rest;
	};

	vector<Edge> edge;
	vector<vector<int>> G;
	vector<bool> vis;
	vector<int> level;

	void init (int N) {
		G = vector<vector<int>> (N+1);
		vis = vector<bool> (N+1, false);
		level = vector<int> (N+1, -1);
	}

	void add_edge (int u, int v, long long cap) {
		edge.push_back ( {u, v, cap, cap} );
		edge.push_back ( {v, u, 0, 0LL} );
		int m = edge.size();
		G[u].emplace_back (m-2);
		G[v].emplace_back (m-1);
	}

	bool bfs (int s, int t) {
		fill (level.begin(), level.end(), -1);
		level[s] = 0;
		queue <int> q;
		q.push (s);
		while (q.size()) {
			int u = q.front();
			q.pop();

			for (auto k: G[u]) {
				Edge &sv = edge[k];
				if (level[sv.v] < 0 && sv.rest > 0) {
					level[sv.v] = level[u] + 1;
					q.push (sv.v);
				}
			}
		}

		return level[t] >= 0;
	}

	long long dfs (int cur, int t, long long bn) {
		if (cur == t) return bn;
		if (bn == 0) return 0LL;

		vis[cur] = true;
		long long s = 0;
		for (auto k: G[cur]) {
			Edge &e = edge[k];
			if (level[cur] + 1 != level[e.v]) continue;
			
			long long f = dfs (e.v, t, min (e.rest, bn));
			if (f > 0) {
				e.rest -= f;
				edge[k^1].rest += f;
				s += f;
				bn -= f;
				if (bn == 0) return s;
			}
		}

		return s;
	}

	long long max_flow (int s, int t) {
		long long ans = 0, mf;
		while (bfs (s, t)) {
			while ( (mf = dfs (s, t, INF)) ) ans += mf;
		}

		return ans;
	}
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, s, t, c, cur = 1;
    while (cin >> n && n > 0) {
        Dinic ff;
        ff.init (n);
        cin >> s >> t >> c;
        int u, v;
        long long cap;
        for (int i = 0; i < c; i++) {
            cin >> u >> v >> cap;
            ff.add_edge (u, v, cap);
            ff.add_edge (v, u, cap);
        }
		
        cout << "Network " << cur++ << '\n';
        cout << "The bandwidth is " << ff.max_flow (s, t) << ".\n";
    }

    return 0;
}
