#include <bits/stdc++.h>

using namespace std;

set<long long int> table;
queue<long long int> q;

int main() {
    long long int ans;
    int n;
    string last;
    vector<int> data(5843);

    q.push(1);
    while (1) {
        long long int keep = q.front();
        if (table.find(keep) == table.end()) {
            table.emplace(keep);
            if (keep < INT_MAX / 2) q.push(keep * 2);
            if (keep < INT_MAX / 3) q.push(keep * 3);
            if (keep < INT_MAX / 5) q.push(keep * 5);
            if (keep < INT_MAX / 7) q.push(keep * 7);
        }
        if (q.size() > 0)
            q.pop();
        else
            break;
    }

    for (n = 1; n <= 5842; n++) {
        data[n] = *table.begin();
        table.erase(table.begin());
    }

    cin >> n;
    while (n != 0) {
        if (n % 10 == 1 && n / 10 % 10 != 1)
            last = "st";
        else if (n % 10 == 2 && n / 10 % 10 != 1)
            last = "nd";
        else if (n % 10 == 3 && n / 10 % 10 != 1)
            last = "rd";
        else
            last = "th";

        ans = data[n];
        cout << "The " << n << last << " humble number is " << ans << ".\n";
        cin >> n;
    }

    return 0;
}
