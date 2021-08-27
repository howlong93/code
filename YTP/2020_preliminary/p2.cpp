#include <bits/stdc++.h>

using namespace std;

int itos (string x) {
	int ret = 0;
	for (size_t i = 0; i < x.size(); i++) ret = ret*10 + x[i]-'0';
	return ret;
}

int main() {
	string input, cur[3];
	cin >> input;
	
	stringstream ss;
	int ch, var = 0, num[3];
	char c;

	ss << input;
	ss >> ch >> c;
	while (getline (ss, cur[var], ',')) var++;

	for (int i = 0; i < 3; i++) {
		if (cur[i] == "") var = i;
		else num[i] = itos(cur[i]);
	}

	if (ch == 1) {
		if (var == 0) cout << (int)sqrt(num[2]*num[2] - num[1]*num[1]) << '\n';
		if (var == 1) cout << (int)sqrt(num[2]*num[2] - num[0]*num[0]) << '\n';
		if (var == 2) cout << (int)sqrt(num[0] * num[0] + num[1] * num[1]) << '\n';
	}
	else if (ch == 2) {
		if (var == 0) cout << num[2]/2 + num[1] << '\n';
		if (var == 1) cout << num[0] - num[2]/2 << '\n';
		if (var == 2) cout << (num[0]-num[1])*2 << '\n';
	}
	else if (ch == 3) {
		if (var == 0) cout << num[2]/num[1] << '\n';
		if (var == 1) cout << num[2]/num[0] << '\n';
		if (var == 2) cout << num[0]*num[1] << '\n';
	}

	return 0;
}
