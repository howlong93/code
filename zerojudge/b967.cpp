#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int num;
    int height;
    int longest_path;
    vector<int> descendant;
};

void build_height(vector<TreeNode> &data, int cur) {
    data[cur].height = 0;
    for (auto k : data[cur].descendant) build_height(data, k);

    for (auto k : data[cur].descendant) {
        data[cur].height = max(data[cur].height, data[k].height + 1);
    }
}

void build_length(vector<TreeNode> &data, int cur) {
    int longest = 0, secondlongest = 0;

    for (auto k : data[cur].descendant) build_length(data, k);

    for (auto k : data[cur].descendant) {
        if (data[k].height + 1 > longest) {
            secondlongest = longest;
            longest = data[k].height + 1;
        } else if (data[k].height + 1 > secondlongest) {
            secondlongest = data[k].height + 1;
        }
    }

    data[cur].longest_path = longest + secondlongest;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, a, b, root;
    while (cin >> n) {
        vector<TreeNode> data(n);
        vector<bool> findroot(n);

        for (int i = 0; i < n; i++) {
            data[i].num = i;
            findroot[i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            findroot[b] = false;
            data[a].descendant.emplace_back(b);
        }

        for (int i = 0; i < n; i++)
            if (findroot[i] == true) {
                root = i;
                findroot[i] = false;
                break;
            }

        build_height(data, root);
        build_length(data, root);

        int ans = 0;
        for (auto k : data) ans = max(ans, k.longest_path);
        cout << ans << '\n';
    }

    return 0;
}
