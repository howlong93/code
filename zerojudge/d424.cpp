#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> height = vector<int> (10050, 0);
	
	int l, r, h, last = 0, front = 10000;
	while (cin >> l >> h >> r) {
		for (int i = l; i < r; i++) height[i] = max (height[i], h);
		last = max (last, r);
		front = min (front, l);
	}
	
	cout << front << ' ' << height[front] << ' ';
	for (int i = front+1; i <= last; i++)
		if (height[i] != height[i-1]) cout << i << ' ' << height[i] << ' ';
	cout << '\n';
	
	return 0;
}
