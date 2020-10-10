#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    while (n--) {
        int amount, i;
        vector<int> list(4);

        cin >> amount >> list[0] >> list[1] >> list[2] >> list[3];

        for (i = 4; i < amount; i++) {
            list.emplace_back(list[i - 4] + list[i - 1]);
        }

        sort(list.begin(), list.end());
        cout << list[amount / 2] << "\n";
    }

    return 0;
}
