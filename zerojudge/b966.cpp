#include <bits/stdc++.h>

using namespace std;

struct Ttype {
    int left, right;
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
    int cur_r = 0, amt;
    long long int ans = 0;

    cin >> amt;
    vector<Ttype> segment(amt);
    for (int i = 0; i < amt; i++) cin >> segment[i].left >> segment[i].right;

    sort(segment.begin(), segment.end(),
         [](Ttype &a, Ttype &b) { return a.left < b.left; });

    for (int i = 0; i < amt; i++) {
        if (cur_r >= segment[i].right) continue;
        if (cur_r >= segment[i].left)
            ans += segment[i].right - cur_r;
        else
            ans += segment[i].right - segment[i].left;

        cur_r = segment[i].right;
    }

    cout << ans << '\n';
}
