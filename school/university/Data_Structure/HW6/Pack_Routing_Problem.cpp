#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

class Node {
  public:
	int val;
	int indegree, outdegree;
	int s, f;
	vector<pair<int, int>> adj;

	void init(int i) {
		val = i;
		s = f = INF;
		indegree = outdegree = 0;
	}
};

void dfs(int);
void print_path (int);

Node nodes[100];
int vis[100] = {0}, top[100], par[100];
int timestamp = 0;
ofstream output;
ifstream input;

int main(int argc, char **argv) {
	input.open (argv[1]);
	output.open (argv[2]);

	int d[100];
	for (int i = 0; i < 100; i++) nodes[i].init(i), d[i] = INF, par[i] = -1;

	string s;
	while (getline(input, s)) {
		stringstream ss;
		string capt;
		int u, v, w;
		ss << s;
		ss >> u >> capt >> v >> capt >> capt >> capt >> w;
		
		nodes[u].adj.push_back({v, w});
		nodes[u].outdegree++;
		nodes[v].indegree++;
	}

	for (int i = 0; i < 100; i++)
		if (!vis[i] && nodes[i].adj.size() > 0) dfs (i);

	sort (nodes, nodes+100, [](const Node &a, const Node &b) {
			return a.f > b.f;
		  });

	for (int i = 0; i < 100; i++) top[nodes[i].val] = i;

	int shortest_path_length = INF, short_end = -1;
	for (int i = 0; i < 100; i++) {
		if (nodes[i].f == INF) continue;
		int cur = nodes[i].val;
		if (nodes[i].indegree == 0) d[cur] = 0;

		for (size_t j = 0; j < nodes[i].adj.size(); j++) {
			int k = nodes[i].adj[j].first, weight = nodes[i].adj[j].second;
			if (d[k] > d[cur] + weight) {
				d[k] = d[cur] + weight, par[k] = cur;
			}
		}

		if (nodes[i].outdegree == 0) {
			if (shortest_path_length > d[cur]) {
				shortest_path_length = d[cur], short_end = cur;
			}
		}
	}
	output << "Shortest Path Length:\n" << shortest_path_length << "\nShortest Path:\n";
	print_path (par[short_end]);
	output << short_end << '\n';

	return 0;
}

void print_path (int cur) {
	if (cur == -1) return;
	print_path (par[cur]);
	output << cur << " -> ";

	return;
}

void dfs (int cur) {
	nodes[cur].s = timestamp++;
	vis[cur] = 1;
	for (size_t i = 0; i < nodes[cur].adj.size(); i++) {
		int tmp = nodes[cur].adj[i].first;
		if (!vis[tmp]) dfs (tmp);
	}
	nodes[cur].f = timestamp++;

	return;
}
