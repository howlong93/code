#include <iostream>

using namespace std;

int main() {
    int i = 0, sum = 0, keep = 0;

    for (i = 0; i < 4; i++) {
        cin >> keep;
        sum += keep;
    }

    cout << sum << " " << sum / 4;

    return 0;
}
