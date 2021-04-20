#include <bits/stdc++.h>
using namespace std;
struct pj {
    long long int s, f, p;
};
bool cmp(pj a, pj b) {
    return b.f > a.f;
}
vector<pj> a;

long long int find(long long int index) {
    long long int low = 0, high = index;
    while (high >= low) {
        long long int mid = (high + low) / 2;
        if (a.at(mid).f < a.at(index).s) {
            if (a.at(mid + 1).f < a.at(index).s) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n;
    cin >> n;

    vector<pj> pje;
    pje.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pje[i].s >> pje[i].f >> pje[i].p;
    }
    sort(pje.begin(), pje.end(), cmp);
    long long int maxpro[pje.size()];
    maxpro[0] = pje[0].p;

	a = pje;
    for (int i = 1; i < pje.size(); i++) {
        long long int q;
        if (find(i) != -1) {
            q = maxpro[find(i)];
        } else {
            q = 0;
        }
        maxpro[i] = max(q + pje[i].p, maxpro[i - 1]);
    }
    cout << maxpro[pje.size() - 1] << endl;

    return 0;
}
