#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long int bottom = 0, top = 0, cnt = 0;

    while (cin >> bottom >> top) {
        cnt = (int)(top * (log10(bottom))) + 1;
        cout << cnt << "\n";
    }

    return 0;
}
