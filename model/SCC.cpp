#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> adj[100000];
vector<int> rev[100000];
vector<int> SCC[100000];
int vis[1000000];
vector<int> W;

void dfs1(int n) {
    vis[n] = 1;
    for(auto i: rev[n]) {
        if(!vis[i]) dfs1(i);
    }
    W.push_back(n);
}

int cnt;
void dfs2(int n) {
    vis[n] = 1;
    SCC[cnt].push_back(n);
    for(auto i: adj[n]) {
        if(!vis[i]) dfs2(i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    for(int i=0;i<n;i++) dfs1(i);
    for(int i=0;i<n;i++) vis[i] = 0;
    reverse(W.begin(), W.end());
    for(auto i: W) {
        dfs2(i), cnt++;
    }
    // 
}
