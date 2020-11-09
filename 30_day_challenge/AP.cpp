#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int stamp = 0;
vector<int> graph[MAXN];
int vis[MAXN], ap[MAXN], low[MAXN];

//get ap during dfs tree
void DFS (int x, int p) {
	vis[x] = low[x] = ++stamp;
	int child = 0;
	for (auto k: graph[x]) {
		if (!vis[k]) {
			child++;
			DFS(k, x);
			low[x] = min (low[x], low[k]);
			if (low[k] >= low[x]) ap[x] = 1;
		}
		else if (vis[k] < vis[x] && k != p)
			low[x] = min (low[x], vis[k]);
	}
	//0 is the lowest num in graph
	if (p <= 0 && child == 1) ap[x] = 0;
}

int main() {
	int n, m;

	//TODO
	
	return 0;
}
