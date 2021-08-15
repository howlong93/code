#include <bits/stdc++.h>

using namespace std;

string s1, s2;
vector<vector<int>> mem;

int dp (int i, int j) {
	if (i == 0) return 4*j;
	if (j == 0) return 3*i;
	if (mem[i][j] != INT_MAX) return mem[i][j];
	
	if (s1[i-1] == s2[j-1]) return mem[i][j] = dp (i-1, j-1);

	return mem[i][j] = min ({3+dp(i-1, j), 4+dp(i, j-1), 5+dp(i-1, j-1)});
}

int main() {
	getline(cin, s1);
	getline(cin, s2);
	
	mem = vector<vector<int>> (s1.size()+1, vector<int> (s2.size()+1, INT_MAX));
	
	cout << dp (s1.size(), s2.size()) << '\n';
	
	return 0;
}
