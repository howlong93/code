#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int q_amt;
	cin >> q_amt;
	map<long long, int> data;
	long long num = 0;
	
	while (q_amt--) {
		int op;
		cin >> op;
		
		if (op == 3) {
			auto it = data.begin();
			cout << it->first + num << '\n';
			if (it -> second == 1) data.erase (it);
			else it->second--;
		}
		else if (op == 2) {
			int tmp;
			cin >> tmp;
			num += tmp;
		}
		else if (op == 1) {
			int tmp;
			cin >> tmp;
			data[tmp-num]++;
		}
	}
	
	return 0;
}
