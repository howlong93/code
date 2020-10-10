#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    string input;

    cin >> n;
    while (n--) {
        stack<char> action;
        int cnt = 0;
        cin >> input;

        for (char k : input) {
            if (k == 'p')
                action.push(0);
            else if (k == 'q' && !action.empty()) {
                action.pop();
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
