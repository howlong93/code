#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> tree[100005];

int cnt = 0;
void dfs(int, int, bool *);

vector<int> bottom;

int main() {
    int amount = 0, a = 0, b = 0, i = 0, ancestor = -1;
    cin >> amount;

    vector<int> leaves;

    for (i = 0; i < amount - 1; i++) {
        cin >> a >> b;
        if (ancestor == -1 || ancestor == b) ancestor = a;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    bool visited[amount] = {false};
    dfs(ancestor, 0, visited);

    for (auto k : bottom) {
        leaves.emplace_back(k);
    }

    for (auto k : leaves) {
        bool visited[amount] = {false};
        dfs(k, 0, visited);
    }

    cout << cnt;
}

void dfs(int pos, int keep, bool *visited) {
    visited[pos] = true;
    bool flag = 0;
    for (auto k : tree[pos]) {
        if (!visited[k]) {
            flag = true;
            dfs(k, keep + 1, visited);
        }
    }

    if (keep > cnt && !flag) {
        bottom.clear();
        bottom.emplace_back(pos);
    } else if (keep == cnt) {
        bottom.emplace_back(pos);
    }
    cnt = max(keep, cnt);
}
