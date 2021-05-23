#include <bits/stdc++.h>

using namespace std;

long long time (int x) {
	long long ret = 1;
	for (int i = 0; i < x; i++) ret *= 10;

	return ret;
}

string v1, v2, v3;
map <char, long long> top, bot, tot;
vector<int> num;

bool check_a (char c) {
	return (c == v1[0] || c == v2[0] || c == v3[0]);
}

void recur () {
	long long ans = 0;
	bool flag;

	do {
		flag = true, ans = 0;
		int i = 0;
		for (auto k: tot) {
			if (check_a (k.first) && num[i] == 0) flag = false;
			ans += 1ll * k.second * num[i++];
		}
		if (ans == 0 && flag) {
			i = 0;
			for (auto &k: tot) {
				k.second = num[i++];
			}
			for (auto k: v1) cout << tot[k];
			cout << '\n';
			for (auto k: v2) cout << tot[k];
			cout << '\n';
			for (auto k: v3) cout << tot[k];
			cout << '\n';
			return;
		}
	} while (next_permutation (num.begin(), num.end()));

	cout << "UNSOLVABLE\n";
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> v1 >> v2 >> v3;

	for (size_t i = 0; i < v1.size(); i++)	tot[v1[i]] += time(v1.size()-i-1);
	for (size_t i = 0; i < v2.size(); i++)	tot[v2[i]] += time(v2.size()-i-1);

	for (size_t i = 0; i < v3.size(); i++)	tot[v3[i]] -= time(v3.size()-i-1);

	num = vector<int> (10);
	for (int i = 0; i < 10; i++) num[i] = i;
	if (tot.size() > 10) {
		cout << "UNSOLVABLE\n";
		return 0;
	}

	recur();

	return 0;
}
