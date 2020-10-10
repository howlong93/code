#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> data;
    int n, input;
    cin >> n;

    while (n--) {
        cin >> input;
        data[input]++;
    }

    for (auto k : data) {
        cout << k.first << " " << k.second << "\n";
    }

    return 0;
}
