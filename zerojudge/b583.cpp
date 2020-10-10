#include <bits/stdc++.h>

using namespace std;

int ani, rel;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int test_amount;
    cin >> test_amount;

    while (test_amount--) {
        bool flag = false;
        int a, b;
        vector<int> admat[1005];
        cin >> ani >> rel;
        int ind[1005] = {0};
        queue<int> q;

        for (int i = 0; i < rel; i++) {
            cin >> a >> b;
            ind[a]++;
            admat[b].emplace_back(a);
        }

        for (int i = 1; i <= ani; i++)
            if (ind[i] == 0) q.push(i);

        while (q.size()) {
            int keep = q.front();
            q.pop();
            for (auto k : admat[keep]) {
                ind[k]--;
                if (ind[k] == 0) q.push(k);
            }
        }

        for (int i = 1; i <= ani; i++) {
            if (ind[i] > 0) {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "O______O\n";
        else
            cout << "W+W\n";
    }

    return 0;
}
