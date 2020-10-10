#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.clear();
    string input;
    bool flag = false;

    while (getline(cin, input)) {
        int cnt = 0;
        for (auto k : input) {
            if (isupper(k) || islower(k)) {
                if (!flag) flag = true;
            } else if (flag == true) {
                flag = false;
                cnt++;
            }
        }
        if (flag) cnt++;
        cout << cnt << "\n";
    }

    return 0;
}
