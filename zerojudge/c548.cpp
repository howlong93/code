#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> num = vector<int> (k+1), pfsum = vector<int> (k+1);
	map<int, int> data;

	for (int i = 0; i <= k; i++) cin >> num[i];
	pfsum[0] = num[0] % k;
	data[pfsum[0]] = 1;

	if (pfsum[0] == 0) {
		cout << "1\n1\n";
		return 0;
	}

	for (int i = 1; i <= k; i++) {
		pfsum[i] = (pfsum[i-1] + num[i]) % k;
		if (num[i]%k == 0) {
			cout << "1\n" << i+1 << '\n';
			break;
		}
		if (pfsum[i]%k == 0) {
			cout << i+1 << '\n';
			for (int j = 1; j <= i+1; j++) cout << j << ' ';
			cout << '\n';
			return 0;
		}
		if (data[pfsum[i]]) {
			cout << i-data[pfsum[i]]+1 << '\n';
			for (int j = data[pfsum[i]]+1; j <= i+1; j++) cout << j << ' ';
			cout << '\n';

			break;
		}
		data[pfsum[i]] = i+1;
	}

	return 0;
}
