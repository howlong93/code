#include <iostream>

using namespace std;

int main() {
    long long int cnt = 0, cur = 0;
    string input;
    cin >> input;

    for (auto k : input) {
        if (k == '0')
            cur++;
        else
            cnt += cur;
    }

    cout << cnt;
}
