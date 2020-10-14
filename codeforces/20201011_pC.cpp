#include <bits/stdc++.h>

using namespace std;

int main() {
    int tstamt;
    cin >> tstamt;

    for (int cur = 0; cur < tstamt; cur++) {
        long long int n;
        cin >> n;

        vector<long long int> num(n);
        vector<pair<long long int, long long int>> mem;
        for (int i = 0; i < n; i++) num[i] = i + 1;

        while (num.size() > 1) {
            int a = num[num.size() - 1], b = num[num.size() - 2];
            mem.emplace_back(make_pair(a, b));
            num.erase(num.begin() + num.size() - 2, num.end());
            num.emplace_back((a + b + 1) / 2);
        }

        cout << num[0] << '\n';
        for (auto k : mem) cout << k.first << ' ' << k.second << '\n';
    }

    return 0;
}
