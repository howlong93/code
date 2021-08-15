#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

vector<long long> num, pfsum;
pair<long long, long long> ans;
double ans_val = 2147483647;

long long gcd (long long x, long long y) {
	if (x < y) swap (x, y);
	while (y > 0) {
		x %= y;
		swap (x, y);
	}
	
	return x;
}
		
void recur (int l, int r) {
	if (l >= r) return;
	
	pair<long long, long long> tmp;
	tmp.x = pfsum[r]-pfsum[l-1];
	tmp.y = r-l+1;
	long long div = gcd (tmp.x, tmp.y);
	tmp.x /= div, tmp.y /= div;
	double v = 1.0 * tmp.x/tmp.y;
	if (ans_val > v) ans = tmp;//, cout << l << ' ' << r << '\n';

	if (num[l-1] <= num[r-1]) recur (l+1, r);
	if (num[l-1] >= num[r-1]) recur (l, r-1);
}

int main() {
	int n;
	cin >> n;
	
	num = vector<long long> (n, 0);
	pfsum = vector<long long> (n+1, 0);
	
	for (int i = 0; i < n; i++) cin >> num[i];
	pfsum[0] = 0;
	for (int i = 0; i < n; i++) pfsum[i+1] = pfsum[i] + num[i];
	
	recur (1, n);
	
	cout << ans.x << ' ' << ans.y << '\n';
	
	return 0;
}
