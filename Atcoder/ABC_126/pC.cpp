#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, cur;
	cin >> n >> k;

	double temp, ans = 0;
	for (int i = 1; i <= n; i++) {
		cur = 1;
		while (cur*i < k) cur *= 2;
		temp = 1.0/(n*cur);
		ans += temp;
	}

	printf ("%.10f\n", ans);

	return 0;
}
