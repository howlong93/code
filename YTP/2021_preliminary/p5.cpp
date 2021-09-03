#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;

	long long ans = 0;
	long long minln = min (n, m);
	for (long long i = 1; i < minln; i++) ans += (n-i) * (m-i) * i * i;

	long long vert, hor;
	for (vert = 1; vert <= n; vert++) {
		for (hor = 1; vert + hor <= minln; hor++) {
			ans += (n-vert-hor) * (m-vert-hor) * (vert*vert + hor*hor);
		}
	}

	cout << ans << '\n';

	return 0;		
}
