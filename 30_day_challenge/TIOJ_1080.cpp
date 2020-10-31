#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define ipr pair<int, int>
#define MAX 100005

vector<ll> bit;
//ipr num[MAX];
ll amt;

void add(ll pos) {
    while (pos <= amt) {
        bit[pos]++;
        pos += pos & (-pos);
    }
}

int query(ll pos) {
    ll ans = 0;
    while (pos > 0) {
        ans += bit[pos];
        pos -= pos & (-pos);
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int cur = 1;
    cin >> amt;
    while (amt != 0) {
		bit = vector<ll> (amt+1, 0);
        ll ans = 0, keep;
		vector<ll> save (amt+1);
		map<ll, ll> num;

        for (ll i = 0; i < amt; i++) {
            cin >> save[i];
            num[save[i]] = 0;
        }
		keep = 1;
		for (auto &k: num) k.second = keep++;
		for (auto &k: save)
			k = num[k];

        for (int i = 0; i < amt; i++) {
            ans += i - query(save[i]);
            add(save[i]);
        }

        cout << "Case #" << cur++ << ": " << ans << '\n';
        cin >> amt;
    }

    return 0;
}
