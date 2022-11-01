#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
	cin >> x >> y;
	
	cout << y/2 - (x-1)/2 + (x == 0) << '\n';
	
	return 0;
}
