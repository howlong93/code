#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000005

int main() {
    int n = 0, i = 0, cnt = 0, fin = 0, start = INT_MAX;
    vector<int> left, right;
    cin >> n;

    for (i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        start = min(start, a);
        fin = max(fin, b);

        left.push_back(a);
        right.push_back(b);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    n = 0;
    for (unsigned int l = 0; l < left.size(); l++) {
        if (n > left[l])
            cnt += right[l] - n;
        else
            cnt += right[l] - left[l];

        n = right[l];
    }

    cout << cnt;

    return 0;
}
