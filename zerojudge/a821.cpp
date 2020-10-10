#include <bits/stdc++.h>

using namespace std;

struct datatype {
    set<string> loser;
    int cnt_win = 0, cnt_lose = 0;
};

int main() {
    int team, test, i;
    string win, lose;

    cin >> team >> test;

    map<string, datatype> data;

    for (i = 0; i < test; i++) {
        cin >> win >> lose;
        if (data[win].loser.find(lose) == data[win].loser.end()) {
            data[win].loser.emplace(lose);
            data[win].cnt_win++;
            data[lose].cnt_lose++;
        }
    }

    for (auto k : data) {
        if (k.second.cnt_win == team - 1 && k.second.cnt_lose == 0) {
            cout << k.first << "\n";
            break;
        }
    }

    return 0;
}
