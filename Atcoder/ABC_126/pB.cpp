#include <bits/stdc++.h>

using namespace std;

int main() {
	string input;
	cin >> input;

	bool first, second;
	first = second = false;

	if (input[0] == '0' && input[1] != '0') first = true;
	else if (input[0] == '1' && input[1] <= '2') first = true;

	if (input[2] == '0' && input[3] != '0') second = true;
	else if (input[2] == '1' && input[3] <= '2') second = true;

	if (first & second) cout << "AMBIGUOUS\n";
	else if (first) cout << "MMYY\n";
	else if (second) cout << "YYMM\n";
	else cout << "NA\n";

	return 0;
}
