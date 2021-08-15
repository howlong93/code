#include <bits/stdc++.h>

using namespace std;

int main() {
	int p, s, dif;
	cin >> p >> s >> dif;
	
	if (p <= s) cout << "None\n";
	else if (p * s * dif % (p-s) != 0) cout << "None\n";
	else cout << p*s*dif/(p-s) << '\n';
	
	return 0;
}
