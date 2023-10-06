#include <iostream>
#include <vector>

using namespace std;

//save digits in reverse order >> num[0] is LSB
void stoi (vector<int> &num, string s) {
	for (int i = s.size()-1; i >= 0; i--) num.emplace_back (s[i]-'0');
	return;
}

ostream& operator<<(ostream& out, const vector<int> &num) {
	for (int i = num.size()-1; i >= 0; i--) out << num[i];
	return out;
}

vector<int> subtr (const vector<int> &a, const vector<int> &b) {
	vector<int> ret = a;

	for (size_t i = 0; i < b.size(); i++) {
		while (ret[i] < b[i]) ret[i] += 10, ret[i+1]--;
		ret[i] -= b[i];
	}

	for (size_t i = b.size(); i < ret.size(); i++) {
		if (ret[i] >= 0) break;
		while (ret[i] < 0) ret[i] += 10, ret[i+1]--;
	}

	for (int i = ret.size()-1; i >= 0; i--) {
		if (ret[i]) break;
		ret.pop_back();
	}

	return ret;
}

void div (vector<int> &num, int d) {
	int r = 0, n = num.size(), tmp;
	for (int i = n-1; i >= 0; i--) {
		tmp = (r*10 + num[i]);
		r = tmp % d;
		num[i] = tmp / d;
	}
	
	for (int i = n-1; i >= 0; i--) {
		if (num[i] != 0) break;
		num.pop_back();
	}

	return;
}

vector<int> multi (vector<int> &num, const vector<int> &x) {
	int c = 0, n = num.size(), m = x.size(), tmp;
	vector<int> ret = vector<int> (n+m, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ret[i+j] += num[i] * x[j];

	for (size_t i = 0; i < ret.size(); i++) {
		tmp = ret[i] + c;
		ret[i] = tmp%10;
		c = tmp/10;
	}

	for (int i = ret.size()-1; i >= 0 ; i--) {
		if (ret[i] > 0) break;
		ret.pop_back();
	}

	return ret;
}

//0 -> a>b ; 1 -> a<b ; 2 -> a==b
int comp (const vector<int> &a, const vector<int> &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = a.size()-1; i >= 0; i--)
		if (a[i] != b[i]) return a[i] < b[i];
	
	return 2;
}

int main() {
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);

	string s;
	vector<int> num1, num2, ans;

	ans = vector<int> (1, 1);
	cin >> s;
	stoi (num1, s);
	cin >> s;
	stoi (num2, s);

	while (comp(num1, {0}) != 2 && comp(num2, {0}) != 2) {
		if (num1[0]%2 == 0 && num2[0]%2 == 0) {
			ans = multi (ans, {2});
			div (num1, 2);
			div (num2, 2);
		}
		else if (num1[0]%2 == 0) div(num1, 2);
		else if (num2[0]%2 == 0) div(num2, 2);

		if (comp(num1, num2) == 2) break;
		if (comp(num1, num2)) swap (num1, num2); //if num1 < num2 swap -> (big first)

		num1 = subtr (num1, num2);
	}

	ans = multi (num2, ans);
	cout << ans << '\n';

	return 0;
}
