#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	
	cout << ((x > y) ? 0 : y-x+1) << '\n';
	
	return 0;
}
