#include <bits/stdc++.h>

using namespace std;

vector<bool> slp;

bool check () {
	int cnt = 0;
	for (int i = 0; i < slp.size(); i++) cnt += slp[i];

	if (cnt <= 1) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> num(n);
	slp = vector<bool> (n, 1);
	
	for (int i = 0; i < n; i++) cin >> num[i];
	int cnt = 1, pos = 0;
	
	while (check()) {
		for (int i = 0; i < n; i++)
			if (i != pos && cnt % num[i] == 0) slp[i] = 0;

		pos = (pos+1) % n;
		while (slp[pos] == 0) pos = (pos+1) % n;
		
		cnt++;
	}
	
	for (int i = 0; i < n; i++) {
		if (slp[i]) cout << i+1 << '\n';
	}
	
	return 0;
}
