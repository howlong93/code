#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string first, second;

    while (1) {
        cin >> first;
        if (first == "STOP!!")
            break;
        else
            cin >> second;

        int save_1[127] = {'\0'}, save_2[127] = {'\0'};
        bool flag = true;

        for (auto k : first) {
            save_1[int(k)]++;
        }

        for (auto k : second) {
            save_2[int(k)]++;
        }

        for (int i = 33; i <= 126; i++) {
            if (save_1[i] != save_2[i]) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
