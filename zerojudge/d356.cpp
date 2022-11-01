#include <bits/stdc++.h>

using namespace std;

int main() {
	double num, sum = 0, i = 0;
	
	cin >> num;
	for (i = 1; sum <= num; i++) sum += 1/i;
	
	cout << --i << '\n';
	
	return 0;
}
