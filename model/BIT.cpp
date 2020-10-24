#include <bits/stdc++.h>

using namespace std;

#define BIT_SIZE 100001
int lnth;
int bit[BIT_SIZE];

//update index
void add (int pos, int val) {
	while (pos <= lnth) {
		bit[pos] += val;
		pos += pos & (-pos);
	}
}

//prefix sum A[pos]
int psum (int pos) {
	int ans = 0;
	while (pos > 0) {
		ans += bit[pos];
		pos -= pos & (-pos);
	}

	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//TODO


	return 0;
}
