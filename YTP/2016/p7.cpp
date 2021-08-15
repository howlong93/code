#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int tmp = a;
	a = b*6 + c*8;
	c = b/2;
	b = tmp/2;
	
	cout << a << ' ' << b << ' ' << c << '\n';
	
	return 0;
}
