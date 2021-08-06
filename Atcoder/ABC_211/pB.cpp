#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> cnt(4, 0);
	
	for (int i = 0; i < 4; i++) {
		string a;
		cin >> a;
		
		if (a == "HR") cnt[0]++;
		else if (a == "H") cnt[1]++;
		else if (a == "2B") cnt[2]++;
		else if (a == "3B") cnt[3]++;
	}
	
	for (int i = 0; i < 4; i++)
		if (cnt[i] == 0) {
			cout << "No\n";
			return 0;
		}

	cout << "Yes\n";
	
	return 0;
}
