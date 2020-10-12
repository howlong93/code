#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    unsigned int cnt = 0, i = 0;
    string pre, post, cur;

    cin >> cur;

    for (i = 0; i < cur.size(); i += 2) {
        for (cnt = 0; cnt < cur[i] - '0'; cnt++) {
            pre += cur[i + 1];
        }
    }

    cnt = 1;
    for (i = 1; i < cur.size(); i++) {
        if (cur[i] == cur[i - 1]) {
            cnt++;
        } else {
            post += cnt + '0';
            post += cur[i - 1];
            cnt = 1;
        }
    }
    post += cnt + '0';
    post += cur[i - 1];

    cout << pre << "\n" << post << "\n";

    return 0;
}
