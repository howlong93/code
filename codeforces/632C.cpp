#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<string> input (n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	sort (input.begin(), input.end(), [] (string &a, string &b) {
		return a+b < b+a;
	});
	
	for (auto k: input) cout << k;
	cout << '\n';
	
	return 0;
}
