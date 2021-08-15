#include <bits/stdc++.h>

using namespace std;

bool check (char a, char b) {
	if (a == 'o' || a == 'v' || a == 'x' || a == 'w' || a == '8') {
		return a == b;
	}
	if (a == 'b') return b == 'd';
	if (a == 'd') return b == 'b';
	if (a == 'p') return b == 'q';
	if (a == 'q') return b == 'p';

	return false;
}

int main() {
	string s, ret;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int l = i, r = i;
		while (l >= 0 && r < s.size() && check (s[l], s[r])) l--, r++;
		r--, l++;
		ans = max (ans, r-l+1);
		if (ans == r-l+1) ret = s.substr(l, r-l+1);
		
		l = i, r = i+1;
		while (l >= 0 && r < s.size() && check (s[l], s[r])) l--, r++;
		r--, l++;
		ans = max (ans, r-l+1);
		if (ans == r-l+1) ret = s.substr(l, r-l+1);
	}
	
	if (ans != 0) cout << ret << '\n';
	else cout << "...\n";
	
	return 0;
}
