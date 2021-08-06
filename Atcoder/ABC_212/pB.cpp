#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> num(4);
	for (int i = 0; i < 4; i++) num[i] = n%10, n /= 10;
	
	if (num[0] == num[1] && num[1] == num[2] && num[2] == num[3]) cout << "Weak\n";
	else if ( (num[0]+9)%10 == num[1] && (num[1]+9)%10 == num[2] && (num[2]+9)%10 == num[3]) cout << "Weak\n";
	else cout << "Strong\n";
	
	return 0;
}
