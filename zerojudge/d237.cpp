#include <iostream>

using namespace std;

#define MAX 2000005

bool isprime[MAX];

void build_table(int);

int main() {
    int i;
    long long int sum = 0;
    for (i = 2; i <= 2000000; i++) isprime[i] = true;

    build_table(2);

    for (i = 2; i <= 2000000; i++)
        if (isprime[i]) sum += i;

    cout << sum << "\n";

    return 0;
}

void build_table(int x) {
    if (x >= 15000) return;
    if (!isprime[x])
        build_table(x + 1);
    else {
        // cout << x << "\n";
        int i = x + x, cnt = 0;
        for (; i <= MAX; i += x) {
            isprime[i] = false;
            // cout << i << " ";
            cnt++;
            // if (cnt % 10 == 0) cout << "\n";
        }
        // cout << "\n\n";

        build_table(x + 1);
    }
}
