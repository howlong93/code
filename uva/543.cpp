#include <bits/stdc++.h>

using namespace std;

#define bv vector<bool>
#define iv vector<int>

#define MAX 1000001

bv prime (MAX, 1);
iv prime_num;
void build_table () {
	for (int i = 2; i*i <= MAX-1; i++) {
		if (prime[i]) {
			if (i != 2) prime_num.emplace_back (i);
			for (int j = 2*i; j <= MAX-1; j += i)
				prime[j] = 0;
		}
	}
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;

	build_table();

	while (cin >> n && n > 0) {
		for (auto k: prime_num) {
			if (prime[n-k]) {
				cout << n << " = " << k << " + " << n-k << '\n';
				break;
			}
		}
	}

	return 0;
}
