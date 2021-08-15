#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	cout << a << ' ' << b << ">>>>\n";
	while (b > 1 && a > 1) {
		a = a % b;
		swap (a, b);
	}
	
	return min (a, b);
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int p = -1, q = -1, r = -1;
	while (p != a || q != b || r != c) {
		cout << "start\n";
		p = a, q = b, r = c;
		int tmp = a;
		a = b*6 + c*8;
		c = b/2;
		b = tmp/2;

		cout << a << ' ' << b << ' ' << c << " gcd\n";
		if (a * b * c) {
			int m = gcd (a, b), n = gcd (b, c);
			int fin = gcd (m, n);
			
			a /= fin, b /= fin, c /= fin;
			cout << a << ' ' << b << ' ' << c << " >> " << p << ' ' << q << ' ' << r << '\n';
		}
	}

	cout << a << ' ' << b << ' ' << c << '\n';

	return 0;
}
