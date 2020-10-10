#include <iostream>

using namespace std;

bool if_prime(int);

int main() {
    int left = 0, right = 0;
    while (cin >> left >> right) {
        long long int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (i == 1) continue;
            if (if_prime(i)) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}

bool if_prime(int num) {
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}
