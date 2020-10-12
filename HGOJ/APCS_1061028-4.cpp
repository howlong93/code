#include <bits/stdc++.h>

using namespace std;

struct Ttype {
    int weight;
    int t;
};

int main() {
    int n;
    while (cin >> n) {
        long long int ans = 0, keep = 0;

        Ttype item[n];

        for (int i = 0; i < n; i++) cin >> item[i].weight;
        for (int i = 0; i < n; i++) cin >> item[i].t;

        sort(item, item + n,
             [](Ttype a, Ttype b) { return a.weight * b.t < b.weight * a.t; });

        for (int i = 0; i < n - 1; i++) {
            keep += item[i].weight;
            ans += item[i + 1].t * keep;
        }

        cout << ans << '\n';
    }

    return 0;
}
