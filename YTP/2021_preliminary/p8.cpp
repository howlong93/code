#include <bits/stdc++.h>

using namespace std;

const long long hash_val = 3559, mod = 1e9+7;

long long fpow (long long a, long long b, long long p) {
	long long tmp = a, ret = 1;
	while (b) {
		if (b % 2) ret = ret * tmp % p;
		tmp = tmp * tmp % p;
		b >>= 1;
	}

	return ret;
}

long long hash_func (char c, long long pos) {
	long long origin;
	if (c == '>') origin = 1;
	else if (c == '<') origin = 2;
	else if (c == '+') origin = 3;
	else if (c == '-') origin = 4;
	else if (c == '.') origin = 5;
	else if (c == ',') origin = 6;
	else if (c == '[') origin = 7;
	else if (c == ']') origin = 8;

	return origin * fpow(hash_val, pos, mod);
}

int main() {
	int n, q_amt;
	cin >> n >> q_amt;
	vector<vector<int>> table(n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		table[i] = vector<int> (s.size(), 0);
		for (int j = 0; j < s.size(); j++) {
			if (j == 0) table[i][j] = hash_func (s[j], j);
			else table[i][j] = (hash_func (s[j], j) + table[i][j-1]) % mod;
		}
	}

	for (int i = 0; i < q_amt; i++) {
		int a, b;
		bool flag = false;
		cin >> a >> b;
		
		int a_size = table[a].size(), b_size = table[b].size();
		int l = 0, r = min(a_size, b_size);

		while (l < r) {
			int mid = (l+r)/2;
			if (table[a][mid] == table[b][mid] && table[a][mid+1] != table[b][mid+1]) {
				cout << mid+1 << '\n', flag = true;
				break;
			}
			
			if (table[a][mid] == table[b][mid]) l = mid+1;
			else r = mid;
		}
		if (!flag) cout << 0 << '\n';
	}

	return 0;
}
