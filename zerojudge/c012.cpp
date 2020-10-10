#include <bits/stdc++.h>

using namespace std;

struct Save {
    int ascii;
    int cnt;
};

int main() {
    string input;

    while (getline(cin, input)) {
        vector<Save> data;
        for (auto k : input) {
            bool flag = true;
            for (auto &l : data)
                if (l.ascii == k) {
                    l.cnt++;
                    flag = false;
                }

            if (flag) {
                Save element;
                element.cnt = 1;
                element.ascii = k;
                data.emplace_back(element);
            }
        }

        sort(data.begin(), data.end(), [](Save &a, Save &b) {
            if (a.cnt != b.cnt) {
                return a.cnt < b.cnt;
            } else {
                return a.ascii > b.ascii;
            }
        });

        for (auto k : data) cout << k.ascii << " " << k.cnt << "\n";

        cout << "\n";
    }

    return 0;
}
