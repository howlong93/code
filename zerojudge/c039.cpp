#include <iostream>

using namespace std;

int calc(int);

int main() {
    int low = 0, high = 0, i = 0;
    while (cin >> low >> high) {
        int cnt = 0;
        for (i = min(low, high); i <= max(low, high); i++) {
            cnt = max(cnt, calc(i));
        }
        cout << low << " " << high << " " << cnt << "\n";
    }

    return 0;
}

int calc(int num) {
    int cnt = 0;
    while (num != 1) {
        cnt++;
        if (num % 2 == 0)
            num /= 2;
        else
            num = num * 3 + 1;
    }

    return cnt + 1;
}
