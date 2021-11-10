#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int pos[26];
	string s;
	while (n--) {
		cin >> s;
		for (size_t i = 0; i < s.size(); i++)
			pos[s[i]-'a'] = i;

		int cnt = 0;
		cin >> s;
		for (size_t i = 1; i < s.size(); i++)
			cnt += abs (pos[s[i]-'a'] - pos[s[i-1]-'a']);

		cout << cnt << '\n';
	}

	return 0;
}
