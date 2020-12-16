#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    bool check(const int &lnth) {
        return (lnth * lnth) <= (x * x + y * y);
	}
};

int main() {
	int tst_amt;
	Point dim;

	cin >> tst_amt >> dim.x >> dim.y;

	for (int i = 0; i < tst_amt; i++) {
		int lnth;
		cin >> lnth;
		if (dim.check (lnth))
			cout << "DA\n";
		else 
			cout << "NE\n";
	}

	return 0;
}
