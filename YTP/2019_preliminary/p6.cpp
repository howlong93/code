#include <bits/stdc++.h>

using namespace std;

int main() {
	string input;
	map<int, int> prio;
	while (cin >> input && input != "END") {
		if (input == "INSERT") {
			int n;
			cin >> n;
			prio[n]++;
		}
		else if (input == "POP_SMALL") {
			if (prio.empty()) {
				cout << "Nothing To Do :)\n";
				continue;
			}
			auto it = prio.begin();
			cout << it -> first << '\n';
			it -> second--;
			if (it -> second == 0) prio.erase (it);
		}
		else if (input == "POP_LARGE") {
			if (prio.empty()) {
				cout << "Nothing To Do :)\n";
				continue;
			}
			auto it = prio.end();
			it--;
			cout << it -> first << '\n';
			it -> second--;
			if (it -> second == 0) prio.erase(it);
		}
	}

	return 0;
}
