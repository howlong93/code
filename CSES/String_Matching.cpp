#include <bits/stdc++.h>

using namespace std;

vector<int> fail;
string input;

void build_fail () {
	for (size_t i = 2, j = 0; i < fail.size(); i++) {
		while (j && input[i] != input[j+1]) j = fail[j];
		if (input[j+1] == input[i]) j++;
		fail[i] = j;
	}
}	

int main() {
	int ans = 0;
	string pattern;

	cin >> input >> pattern;
	pattern += "$";
	input = pattern + input;
	input = " " + input;
	int n = input.size();

	fail = vector<int> (n+1, 0);
	build_fail();

	for (size_t i = pattern.size(); i < fail.size(); i++) {
		if (fail[i] == pattern.size()-1) ans++;
	}
	cout << ans << '\n';

	return 0;
}
