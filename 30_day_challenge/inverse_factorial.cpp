#include <bits/stdc++.h>

using namespace std;

int small_num (string n) {
	if (n == "1") return 1;
	if (n == "2") return 2;
	if (n == "6") return 3;
	if (n == "24") return 4;
	if (n == "120") return 5;
	return 6;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;
	int digits = input.size();

	if (digits < 4) {
		cout << small_num (input);
	}
	else {
		int number = 6;
		double cur_dig = log10(720);
		while (1) {
			cur_dig += log10(++number);
			if (cur_dig > digits) {
				cout << number-1 << '\n';
				break;
			}
		}
	}

	return 0;
}
