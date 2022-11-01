#include <bits/stdc++.h>

using namespace std;

int main() {
	int num = 0;
	
	while (cin >> num) {
		if (num < 0) num *= -1;
		
		int sum = 0, amt;
		for (amt = 1; sum < num; amt++) sum += amt;
		
		amt--;
		if (sum == num) cout << amt << '\n';
		else if ((sum - num) % 2 == 0) cout << amt << '\n';
		else if (amt % 2 == 1) cout << amt+2 << '\n';
		else if (amt % 2 == 0) cout << amt+1 << '\n';
		else cout << -1 << '\n';
	}
	
	return 0;
}
