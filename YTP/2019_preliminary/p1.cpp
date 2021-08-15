#include <bits/stdc++.h>

using namespace std;

map<string, int> cnt;
string test[13];

bool check () {
	for (int i = 0; i < 13; i++) {
		if (cnt.find(test[i]) != cnt.end()) ;
		else return false;
	}
	return true;
}

int main() {
	test[0] = "1m", test[1] = "9m", test[2] = "1p", test[3] = "9p";
	test[4] = "1s", test[5] = "9s";
	test[6] = "1z", test[7] = "2z", test[8] = "3z", test[9] = "4z";
	test[10] = "5z", test[11] = "6z", test[12] = "7z";
	
	int T;
	cin >> T;
	while (T--) {
		cnt.clear();
		for (int i = 0; i < 14; i++) {
			string tmp;
			cin >> tmp;
			cnt[tmp]++;
		}
		
		int flag = 0;
		if (check ()) flag = 1;
		else if (cnt.size() == 7) {
			flag = 2;
			for (auto k: cnt) {
				if (k.second != 2) {
					flag = 0;
					break;
				}
			}
		}
		
		if (flag == 1) cout << "kokushi musou(Thirteen orphans)\n";
		else if (flag == 2) cout << "chiitoitsu(Seven pairs)\n";
		else cout << "none\n";
	}
	
	return 0;
}
