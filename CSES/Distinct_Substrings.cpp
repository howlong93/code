#include <bits/stdc++.h>

using namespace std;

vector<int> lcp_array (string s, vector<int> sa, vector<int> rk) {
	int n = s.size();
	vector<int> lcpa (n, 0);
	for (int i = 0; i < n; i++) {
		if (rk[i] == 0) {
			lcpa[rk[i]] = 0;
			continue;
		}
		int lcp = 0;
		if (i > 0) lcp = max (lcpa[rk[i-1]]-1, 0);
		int j = sa[rk[i]-1];
		while (s[i+lcp] == s[j+lcp]) lcp++;
		lcpa[rk[i]] = lcp;
	}

	return lcpa;
}


vector<vector<int>> suffix_array(string s) {
    int n = s.size();
	vector<int> rk = vector<int> (n);
    {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());

        rk[a[0].second] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                rk[a[i].second] = rk[a[i - 1].second];
            } else {
                rk[a[i].second] = i;
            }
        }
    }

    for (int d = 1; d < n; d *= 2) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            if (i + d < n)
                a[i] = {{rk[i], rk[i + d]}, i};
            else
                a[i] = {{rk[i], 0}, i};
        }
        sort(a.begin(), a.end());
        rk[a[0].second] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                rk[a[i].second] = rk[a[i - 1].second];
            } else {
                rk[a[i].second] = i;
            }
        }
    }

    vector<int> sa(n);
    for (int i = 0; i < n; i++) sa[rk[i]] = i;

	vector<int> lcpa = lcp_array (s, sa, rk); 
    return {sa, rk, lcpa};
}

int main() {
    string input;

    cin >> input;
    input += "$";

    vector<vector<int>> sa = suffix_array(input);

	long long lcp_sum = 0, ans;
	for (size_t i = 0; i < sa[2].size(); i++) lcp_sum += sa[2][i];
	ans = (input.size()+1)*input.size()/2 - input.size() - lcp_sum;

	for (size_t i = 0; i < sa[0].size(); i++) {
		cout << sa[0][i] << '\t' << sa[2][i] << '\t' << input.substr (sa[0][i]) << '\n';
	}

	cout << ans << '\n';
	
    return 0;
}
