#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, pos = -1;
	cin >> n;
	string card;
	
	cin >> card;
	
	for (int i = 0; i < n; i++) {
		if (card[i] == '1' && pos == -1) pos = i;
	}
	
	if (pos%2 == 0) cout << "Takahashi\n";
	else cout << "Aoki\n";
	
	return 0;
}
