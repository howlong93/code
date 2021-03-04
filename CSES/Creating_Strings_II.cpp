#include <bits/stdc++.h>

using namespace std;

long long table[1000005], alph[26] = {0};
const long long MOD = 1000000007;

void build_tb() {
	table[0] = table[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		table[i] = (table[i-1] * i) % MOD;
}

long long fastq (long long n, long long m) {
	long long ret = 1;
	while (m) {
		if (m % 2) ret = ret * n % MOD;

		m >>= 1;
		n = n * n % MOD;
	}

	return ret;
}

long long calc_ans (int lnth) {
	long long bot = 1;
	for (int i = 0; i < 26; i++)
		bot = bot * table[alph[i]] % MOD;

	return (table[lnth] * fastq (bot, MOD-2) % MOD);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	build_tb ();

	string s;
	cin >> s;

	for (auto k: s) alph[k-'a']++;

	cout << calc_ans (s.size()) << '\n';

	return 0;
}
