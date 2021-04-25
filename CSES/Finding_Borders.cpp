#include <bits/stdc++.h>

using namespace std;

vector<int> fail;
string input;

void build_fail () {
	fail = vector<int> (input.size(), 0);
	for (size_t i = 2, j = 0; i < fail.size(); i++) {
		while (j && input[i] != input[j+1]) j = fail[j];
		if (input[j+1] == input[i]) j++;
		fail[i] = j;
	}
}	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> input;
	input = " " + input;
	build_fail();
	vector<int> ans;

	for (int i = fail[input.size()-1]; i > 0; i = fail[i]) {
		ans.emplace_back (i);
	}

	for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
