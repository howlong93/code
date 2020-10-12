#include <iostream>
#include <vector>

using namespace std;

void build_table(int);

#define MAX 10005
bool prime[MAX] = {true};

int main() {
    int left = 0, right = 0, cnt = 0, sum = 0;
    vector<int> data;
    cin >> left >> right;

    for (int i = 0; i < MAX; i++) prime[i] = true;

    build_table(2);

    for (int i = left; i <= right; i++)
        if (prime[i]) {
            cnt++;
            sum += i;
            data.emplace_back(i);
        }

    cout << cnt << "\n" << sum << "\n";
    if (cnt > 0) {
        cout << data[0];
        for (int i = 1; i < cnt; i++) {
            cout << " " << data[i];
        }
    }

    return 0;
}

void build_table(int pos) {
    if (pos > 100) return;
    if (!prime[pos]) {
        build_table(pos + 1);
        return;
    }

    for (int i = 2; (pos * i) <= 10000; i++) {
        prime[pos * i] = false;
    }
    build_table(pos + 1);
}
