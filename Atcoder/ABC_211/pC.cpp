#include <bits/stdc++.h>

using namespace std;

map<char, int> conv;

int check (char c) {
	if (conv.find(c) != conv.end()) return conv[c];
	return -1;
}
	
int main() {
	const int mod = 1e9+7;
	
	string s;
	cin >> s;
	
	vector<vector<long long>> dp = vector<vector<long long>> (s.size()+1, vector<long long> (8, 0));
	
	conv['c'] = 0, conv['h'] = 1, conv['o'] = 2, conv['k'] = 3, conv['u'] = 4, conv['d'] = 5;
	conv['a'] = 6, conv['i'] = 7;

	
	for (int i = 1; i <= s.size(); i++) {
		int pos;
		dp[i] = dp[i-1];
		if ((pos = check (s[i-1])) != -1) {
			if (pos == 0) dp[i][0]++;
			else dp[i][pos] = (dp[i][pos] + dp[i][pos-1]) % mod;
		}
	}
	
	cout << dp[dp.size()-1][7] << '\n';
	
	return 0;
}
