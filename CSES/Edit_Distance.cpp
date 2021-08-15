#include <bits/stdc++.h>

using namespace std;

string s1, s2;
vector<vector<int>> mem;

int dp (int i, int j) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	if (i == 0) return j;
	if (j == 0) return i;
	if (mem[i][j] != INT_MAX) return mem[i][j];
	
	if (s1[i-1] == s2[j-1]) return mem[i][j] = dp (i-1, j-1);

	return mem[i][j] = min ({1+dp(i-1, j), 1+dp(i, j-1), 1+dp(i-1, j-1)});
}

int main() {
	getline(cin, s1);
	getline(cin, s2);
	
	mem = vector<vector<int>> (s1.size()+1, vector<int> (s2.size()+1, INT_MAX));
	
	cout << dp (s1.size(), s2.size()) << '\n';
	
	return 0;
}
