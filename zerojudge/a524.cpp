#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;

    while (cin >> n) {
        vector<int> num(n), ans;
        for (i = 1; i <= n; i++) {
            num[i - 1] = i;
        }

        do {
            ans.emplace_back(num[0]);
            int &s = ans[ans.size() - 1];
            for (i = 1; i < n; i++) {
                s = s * 10 + num[i];
            }
        } while (next_permutation(num.begin(), num.begin() + n));

        for (i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << "\n";
        }
    }

    return 0;
}
