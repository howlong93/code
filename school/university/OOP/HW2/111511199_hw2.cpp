#include <iostream>

using namespace std;

int recur (int, int &);

int main() {
	int mon, coup = 0;
	cin >> mon;

	coup = mon;
	cout << recur (mon, coup) << ' ' << coup << '\n';

	return 0;
}

int recur (int amt, int &rest) {
	if (rest < 7) return amt;
	amt += rest/7;
	rest = rest/7 + rest%7;
	return recur (amt, rest);
}
