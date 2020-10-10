#include <iostream>
#include <sstream>

using namespace std;

int gcd(int x, int y);

int main() {
    string input;
    int n;
    cin >> n;

    getline(cin, input);

    while (n--) {
        int ans = 0;
        int data[105] = {0}, i = 0, cnt = 0, j;
        stringstream ss;
        getline(cin, input);

        ss << input;

        while (ss >> data[i++]) cnt++;

        for (i = 0; i < cnt - 1; i++) {
            for (j = i + 1; j < cnt; j++) {
                ans = max(ans, gcd(data[i], data[j]));
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

int gcd(int x, int y) {
    return (x % y == 0) ? y : gcd(y, x % y);
}
