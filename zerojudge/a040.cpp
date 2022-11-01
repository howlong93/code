#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, flag = 0;
	cin >> n >> m;
	
	while (n <= m) {
		int temp = n, time = 0, add = 0;
		while (temp > 0) {
			time++;
			temp /= 10;
		}
		
		temp = n;
		while (temp > 0) {
			int cur = temp % 10, cnt = 1;
			for (int i = 0; i < time; i++) cnt *= cur;
			add += cnt;
			temp /= 10;
		}
		
		if (add == n) cout << n << ' ', flag = true;
		n++;
	}
	
	if (!flag) cout << "none\n";
	
	return 0;
}
