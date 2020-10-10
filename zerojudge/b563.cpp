#include <bits/stdc++.h>

using namespace std;

struct saving_data {
    int cur = 0;
    int dest = 0;
    int cnt = 0;
};

int main() {
    int n, i, ans = 0, j;

    while (cin >> n) {
        ans = 0;
        bool flag;
        int a, b;
        vector<saving_data> data(n);

        for (i = 0; i < n; i++) {
            cin >> a >> b;
            flag = true;
            for (j = 0; j < n; j++) {
                if (data[j].cur == a && data[j].dest == b) {
                    data[j].cnt++;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                data[i].cur = a;
                data[i].dest = b;
                data[i].cnt = 1;
            }
        }

        vector<bool> if_cnt(data.size(), false);

        for (i = 0; i < n; i++) {
            if (!if_cnt[i]) {
                if_cnt[i] = true;
                for (j = i + 1; j < n; j++) {
                    if (data[j].cur == data[i].dest &&
                        data[j].dest == data[i].cur) {
                        if_cnt[j] = true;
                        ans += min(data[i].cnt, data[j].cnt);
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
