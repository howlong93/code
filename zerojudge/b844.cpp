#include <bits/stdc++.h>

using namespace std;

struct button_struct {
    int num;
    bool light;
    bool act;
};

int main() {
    int n, m, i;
    while (cin >> n >> m) {
        vector<button_struct> button(n + m), keep;
        map<int, int> ans;

        for (i = 0; i < n; i++) {
            cin >> button[i].num;
            button[i].light = 1;
            button[i].act = 0;
        }
        for (i = 0; i < m; i++) {
            cin >> button[i + n].num;
            button[i + n].light = 0;
            button[i + n].act = 1;
            keep.emplace_back(button[i + n]);
        }
        sort(button.begin(), button.end(),
             [](button_struct &a, button_struct &b) {
                 if (a.num != b.num)
                     return a.num < b.num;
                 else
                     return a.act < b.act;
             });

        bool light = 0;
        for (i = 0; i < n + m; i++) {
            if (button[i].act)
                ans[button[i].num] = light;
            else
                light = light ^ button[i].light;
        }

        for (auto k : keep) {
            cout << ans[k.num] << "\n";
        }
    }

    return 0;
}
