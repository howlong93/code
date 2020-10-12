#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int keep_fail = -1, keep_pass = 101, amount = 0, k = 0, i = 0;
    vector<int> data;

    cin >> amount;

    for (i = 0; i < amount; i++) {
        cin >> k;
        if (k >= 60) {
            keep_pass = min(keep_pass, k);
        } else
            keep_fail = max(keep_fail, k);

        data.emplace_back(k);
    }

    sort(data.begin(), data.end());
    cout << data[0];
    for (i = 1; i < amount; i++) {
        cout << " " << data[i];
    }
    cout << "\n";

    if (keep_fail == -1)
        cout << "best case\n";
    else
        cout << keep_fail << "\n";
    if (keep_pass == 101)
        cout << "worst case\n";
    else
        cout << keep_pass << "\n";

    return 0;
}
