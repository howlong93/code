#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int base, comp;
	base = c*c;
	comp = a*a + b*b;

	if (comp < base) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
