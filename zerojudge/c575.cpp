#include <bits/stdc++.h>

using namespace std;

int amt, serve;
vector<int> pnt;

int check(int dmtr) {
    int cur, cnt = 1;
    for (int i = 0; i < amt; cnt++) {
        cur = pnt[i] + dmtr;
        if (cnt > serve) return 0;
        if (cur >= pnt[amt - 1]) return 1;

        while (cur >= pnt[i]) i++;
    }

    return 0;
}

int main() {
    cin >> amt >> serve;

    pnt = vector<int>(amt);
    for (int i = 0; i < amt; i++) cin >> pnt[i];

    sort(pnt.begin(), pnt.end());

    int upper = pnt[amt - 1] - pnt[0], lower = 1, mid;

    while (check(upper)) {
        mid = (upper + lower) / 2;
        if (check(mid))
            upper = mid;
        else
            lower = mid + 1;

        if (lower == upper) break;
    }

    cout << upper << '\n';

    return 0;
}
