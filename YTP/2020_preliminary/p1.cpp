#include <bits/stdc++.h>

using namespace std;

int main() {
	int day;
	cin >> day;

	int amt = 5*(day/7 + (day%7 != 0));
	cout << amt << '\n';
	return 0;
}
