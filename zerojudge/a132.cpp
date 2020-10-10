#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    while (n != 0) {
        stack<bool> binary;
        int cnt = 0;
        while (n) {
            binary.push(n % 2);
            n /= 2;
        }

        cout << "The parity of ";

        while (binary.size() > 0) {
            cout << binary.top();
            cnt += binary.top();
            binary.pop();
        }
        cout << " is " << cnt << " (mod 2).\n";
        cin >> n;
    }

    return 0;
}
