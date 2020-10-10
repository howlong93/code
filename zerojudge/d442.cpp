#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
    set<long long int> founded;
    long long int k = x;
    while (k != 1) {
        long long int save = 0;

        while (k > 0) {
            save += (k % 10) * (k % 10);
            k /= 10;
        }

        k = save;

        if (founded.find(k) != founded.end()) break;
        founded.emplace(k);
    }

    if (k == 1)
        return true;
    else
        return false;
}

int main() {
    int n, search, cnt = 1;
    cin >> n;

    while (n--) {
        cin >> search;
        cout << "Case #" << cnt << ": " << search << " is a"
             << (check(search) ? " H" : "n Unh") << "appy number.\n";
        cnt++;
    }

    return 0;
}
