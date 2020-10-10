#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input;

    cin >> input;
    while (input != "0") {
        int cnt = 0, ans = 0;
        bool flag = true;

        for (char k : input) {
            cnt += k - '0';
        }

        if (cnt % 9 != 0)
            flag = false;
        else {
            while (cnt % 9 == 0) {
                string keep;
                stringstream ss;
                ans++;
                if (cnt / 10 == 0) break;
                ss << cnt;
                ss >> keep;
                cnt = 0;
                for (auto k : keep) cnt += k - '0';
            }
        }

        cout << input << " is " << (flag ? "" : "not ") << "a multiple of 9";
        if (flag) {
            cout << " and has 9-degree " << ans << ".\n";
        } else
            cout << ".\n";
        cin >> input;
    }

    return 0;
}
