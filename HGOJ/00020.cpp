#include <iostream>

using namespace std;

#define MAX 10005

int succeed[MAX];

int main() {
    int n = 0;
    cin >> n;

    succeed[1] = 1;
    succeed[2] = 2;
    succeed[3] = 3;
    succeed[4] = -1;

    for (int i = 4; i <= n; i++) {
        succeed[i] = -1;
        for (int j = 1; j <= 3; j++) {
            if (succeed[i - j] == -1) {
                succeed[i] = j;
                break;
            }
        }
    }

    cout << succeed[n];

    return 0;
}
