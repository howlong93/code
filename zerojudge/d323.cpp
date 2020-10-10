#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    cin >> n;

    vector<int> data(n);

    for (i = 0; i < n; i++) {
        cin >> data[i];
    }

    sort(data.begin(), data.end());

    for (auto k : data) {
        cout << k << " ";
    }

    return 0;
}
