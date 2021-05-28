#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (i == k-1) cout << char(input[i]-'A'+'a');
		else cout << input[i];
	}
	cout << '\n';

	return 0;
}
