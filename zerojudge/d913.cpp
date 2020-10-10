#include <bits/stdc++.h>

using namespace std;

int given[6][7], ans[6];

bool compare() {
    int i, j, cnt;

    for (i = 0; i < 6; i++) {
        for (j = 0, cnt = 0; j < 6; j++) {
            if (ans[j] == given[i][j]) cnt++;
        }
        if (cnt != given[i][6]) return false;
    }

    return true;
}

int main() {
    int i, j;

    for (i = 0; i < 6; i++) {
        ans[i] = i + 1;
        for (j = 0; j < 7; j++) {
            cin >> given[i][j];
        }
    }

    do {
        if (compare()) {
            break;
        }
    } while (next_permutation(ans, ans + 6));

    for (i = 0; i < 6; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
