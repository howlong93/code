#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int test_amount;
    cin >> test_amount;

    while (test_amount--) {
        set<int> flower;
        int n, i, j, largest_bag = 0, keep = 0;

        cin >> n;
        vector<int> data(n);
        for (i = 0; i < n; i++) cin >> data[i];

        for (i = 0; i < n; i++) {
            if (n - i < largest_bag) break;

            flower.clear();
            for (j = i; j < n; j++) {
                if (flower.find(data[j]) == flower.end()) {
                    flower.emplace(data[j]);
                } else {
                    keep = flower.size();
                    largest_bag = max(largest_bag, keep);
                    while (data[i] != data[j]) i++;
                    break;
                }
            }
            keep = flower.size();
            largest_bag = max(largest_bag, keep);
        }

        cout << largest_bag << '\n';
    }
    return 0;
}
