#include <iostream>

using namespace std;

int main() {
    int x = 0, y = 0, m, n, cnt = 0;

    while (cnt < 3) {
        cin >> m >> n;
        x += m;
        y += n;
        cnt++;
    }

    cout << x / 3 << " " << y / 3;

    return 0;
}
