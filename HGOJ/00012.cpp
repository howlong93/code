#include <iostream>
#include <vector>

using namespace std;

#define MAX 105

bool ifvisited[MAX] = {false}, succeed = false;
vector<int> data[MAX];

void dfs(int, int);

int main() {
    int from = 0, to = 0, amount = 0, path = 0, i = 0;

    cin >> amount >> path;

    for (i = 0; i < path; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        data[a].emplace_back(b);
    }

    cin >> from >> to;

    dfs(from, to);

    if (succeed)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

void dfs(int pos, int dest) {
    if (succeed) return;

    ifvisited[pos] = true;
    if (pos == dest) {
        succeed = true;
        return;
    }

    for (auto k : data[pos]) {
        if (!ifvisited[k]) dfs(k, dest);
    }
}
