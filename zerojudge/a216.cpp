#include <iostream>

using namespace std;

#define MAX 30005

int main() {
    int day = 0, i;
    long long int f[MAX] = {0}, g[MAX] = {0}, cur = 0;

    f[1] = g[1] = 1;
    while (cin >> day) {
        if (cur >= day) {
            cout << f[day] << " " << g[day] << "\n";
            continue;
        }

        for (i = cur + 1; i <= day; i++) {
            f[i] = f[i - 1] + i;
            g[i] = f[i] + g[i - 1];
        }

        cur = day;
        cout << f[day] << " " << g[day] << "\n";
    }

    return 0;
}
