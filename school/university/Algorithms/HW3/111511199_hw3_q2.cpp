#include <bits/stdc++.h>

using namespace std;

string s, t;
vector<vector<int>> mem;

int dp (int i, int j) { //test on s[i-1] amd t[j-1]
	if (i == 0) return j;  //source empty >> delete all j chars in target
	if (j == 0) return i;  //target empty >> delete all i chars in target
	if (mem[i][j] != INT_MAX) return mem[i][j]; //case finished

	if (s[i-1] == t[j-1]) return mem[i][j] = dp(i-1, j-1); //two chars are same
	return mem[i][j] = 1 + min ({dp(i-1, j), dp(i, j-1), dp(i-1, j-1)});
}

int main() {
	cin >> s >> t;
	mem = vector<vector<int>> (s.size()+1, vector<int> (t.size()+1, INT_MAX));

	cout << dp (s.size(), t.size());

	return 0;
}
