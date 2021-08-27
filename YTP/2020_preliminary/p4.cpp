#include <bits/stdc++.h>

using namespace std;

struct Stype {
	int cnt = 0, home = 0, sum = 0;
	bool tot = false;
	vector<vector<int>> cls;
};

int main() {
	int school_num;
	cin >> school_num;
	vector<Stype> school(school_num);

	for (int i = 0; i < school_num; i++) {
		int cl_num;
	   	cin >> cl_num;
		school[i].cls = vector<vector<int>> (cl_num);

		for (int j = 0; j < cl_num; j++) {
			int st_amt;
		   	cin >> st_amt;
			school[i].cls[j] = vector<int> (st_amt);
			school[i].sum += st_amt;
			while (st_amt--) {
				cin >> school[i].cls[j][st_amt];
				if (school[i].cls[j][st_amt] == 11)
					school[i].cnt++, school[i].home += school[i].cls[j].size();
			}
		}

		if (school[i].cnt >= 2) {
			school[i].tot = true;
			school[i].home = 0;
			for (int j = 0; j < cl_num; j++) 
				school[i].home += school[i].cls[j].size();
		}
	}

	int cnt_schools = 0, ans = 0;
	for (int i = 0; i < school_num; i++) cnt_schools += school[i].tot;
	if (cnt_schools * 3 >= school_num)
		for (int i = 0; i < school_num; i++) ans += school[i].sum;
	else
		for (int i = 0; i < school_num; i++) ans += school[i].home;
		
	cout << ans << '\n';

	return 0;
}
