#include <bits/stdc++.h>

using namespace std;

struct saving_data {
    char c;
    int cnt;
};
vector<saving_data> cnt_alpha;
int unfind_char;

int &find(char k) {
    for (unsigned int i = 0; i < cnt_alpha.size(); i++) {
        if (cnt_alpha[i].c == k) {
            return cnt_alpha[i].cnt;
        }
    }
    return unfind_char;
}

int main() {
    unfind_char = -1;
    string input;
    int n;
    cin >> n;

    getline(cin, input);
    while (n--) {
        getline(cin, input);
        for (auto k : input) {
            if (!isalpha(k)) continue;

            char c = toupper(k);
            int &a = find(c);

            if (a == -1) {
                saving_data unfind;
                unfind.c = c;
                unfind.cnt = 1;
                cnt_alpha.emplace_back(unfind);
            } else {
                a++;
            }
        }
    }

    sort(cnt_alpha.begin(), cnt_alpha.end(),
         [](saving_data &a, saving_data &b) {
             if (a.cnt != b.cnt)
                 return a.cnt > b.cnt;
             else
                 return a.c < b.c;
         });

    for (auto k : cnt_alpha) {
        cout << k.c << " " << k.cnt << "\n";
    }

    return 0;
}
