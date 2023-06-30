#include <iostream>
#include <deque>

using namespace std;

bool less (const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	deque<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		
		bool flag = false;
		cout << "Round " << i+1 << " : ";
		while (arr.size() > 0 && arr[arr.size()-1].first < num) {
			cout << arr[arr.size()-1].second << ' ';
			arr.pop_back();
			flag = true;
		}
		 
		if (!flag && arr.size() >= m) {
			cout << arr[0].second << ' ';
			arr.pop_front();
		}
		cout << '\n';
		
		arr.push_back ({num, i+1});
	}
	
	while (arr.size() > 0) {
		cout << arr[arr.size()-1].second << ' ';
		arr.pop_back();
	}
	
	return 0;
}
