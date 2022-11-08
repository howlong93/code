#include<iostream>
#include <map>

using namespace std;

map<long long, long long> mem;
long long recur (long long k) {
	if (k <= 0) return 1;
	if (mem[k] != 0) return mem[k];
	return mem[k] = recur(k/2) + recur(k/3);
}

int main() {
	long long k;
	cin >> k;

	cout << recur(k) << '\n';

	return 0;
}
