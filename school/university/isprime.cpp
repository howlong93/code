#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001

vector<int> scan (SIZE, 0);
set<int> prime;

void pre_func() {
    scan[0] = scan[1] = 1;
    for (long long i = 2; i <= SIZE; i++) {
        if (scan[i] == 0) {
            for (long long j = 2; j*i <= SIZE; j++) scan[j*i] = 1;
            prime.insert (i);
        }
    }
}

bool isprime(unsigned int x) {
    cout << x << ' ';
    if (x <= SIZE) {
        return (!scan[x]);
    }
    else {
        for (auto k: prime) {
            if (x % k == 0) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    unsigned int x;
    pre_func ();

    while (cin >> x) {
        cout << isprime(x) << '\n';
    }

    return 0;
}
