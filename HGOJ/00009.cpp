#include <iostream>

using namespace std;

long long int fast_mod(long long int base, long long int times,
                       long long int divisor) {
    long long int res, t;
    res = 1 % divisor;
    t = base % divisor;
    while (times) {
        if (times & 1) {
            res = res * t % divisor;
        }
        t = t * t % divisor;
        times >>= 1;
    }
    return res;
}

int main() {
    long long int base = 0, times = 0, divisor = 0, i = 0;

    cin >> i;

    for (int j = 0; j < i; j++) {
        cin >> base >> times >> divisor;
        cout << fast_mod(base, times, divisor) << endl;
    }

    return 0;
}
