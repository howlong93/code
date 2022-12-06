#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

void output (const vi&);

vi num_to_vec (long long x) {
	vi ret;
	while (x) {
		ret.push_back (x%10);
		x /= 10;
	}
	return ret;
}

bool check (const vi &n) {
	for (size_t i = 0; i < n.size(); i++)
		if (n[i] != 0) return true;

	return false;
}

bool compare (const vi &a, const vi &b) {
    if (a.size() < b.size()) return false;
    if (a.size() > b.size()) return true;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) return false;
        if (a[i] > b[i]) return true;
    }
    return true;
}

vi multi (const vi &a, const vi &b) {
//	cout << "running multiplication\n";
    vi ans = vi (a.size() + b.size(), 0);

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < b.size(); j++) {
            ans[i+j] += a[i] * b[j];
            if (ans[i+j] >= 10) {
                ans[i+j+1] += ans[i+j] / 10;
                ans[i+j] = ans[i+j] % 10;
            }
        }
    }

    if (ans[ans.size()-1] == 0) ans.pop_back();

    return ans;
}

long long div (const vi &a, long long b, vi &c) {
//	cout << "running division\n";
	long long r = 0;
	for (int i = a.size()-1; i >= 0; i--) {
		r = r * 10 + a[i];
		c.push_back (r/b);
		r %= b;
	}
	reverse (c.begin(), c.end());
	while (c.size() && c[c.size()-1] == 0) c.pop_back();

	return r;
}

long long fast_pow (vi m, long long e, long long n) {
//	cout << "running power function\n";
	vi ret = {1};
	long long ans;

	while (e) {
		vi temp;
		if (e & 1) {
			ret = multi(ret, m);
			ans = div (ret, n, temp); 
			ret = num_to_vec (ans);
		}
		m = multi (m, m);
		long long remain = div (m, n, temp);
		m = num_to_vec (remain);

		e >>= 1;
	}
	return ans;
}
		
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//input
	long long n, e;
	string s;
	vi temp;

	cin >> n >> e >> s;

	for (size_t i = 0; i < s.size(); i++) {
		temp = num_to_vec (s[i]);
		cout << fast_pow (temp, e, n);
		if (i != s.size()-1) cout << ",";
	}


	return 0;
}
