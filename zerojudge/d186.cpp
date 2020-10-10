#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

void build_table();

bool table[MAX] = {0};

int main() {
    int a, b, i;
    build_table();

    while (cin >> a >> b) {
        int cnt = 0;
        if (a == 0) break;

        for (i = a; i <= b; i++) {
            if (table[i]) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}

void build_table() {
    int i = 1;
    while (i * i <= MAX) {
        table[i * i] = true;
        i++;
    }
}
