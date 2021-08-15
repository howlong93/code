#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	string str;
	str.resize(n);
	vector<string> data;
	for (int i = 0; i < n; i++) str[i] = 'A'+i;
	
	do {
		cout << str << '\n';
	} while (next_permutation (str.begin(), str.end()));
	
	return 0;
}
