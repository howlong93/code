#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> data(n);

    while (n--) {
        cin >> data[n].first >> data[n].second;
    }

    sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    });

    for (auto k : data) {
        cout << k.first << " " << k.second << "\n";
    }

    return 0;
}
