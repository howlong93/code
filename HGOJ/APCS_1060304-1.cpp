#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, i = 0;
    string keep;

    cin >> keep;
    for (i = 0; i < keep.size(); i++) {
        if (i % 2 == 0)
            a += keep[i] - '0';
        else
            b += keep[i] - '0';
    }

    cout << abs(a - b) << "\n";

    return 0;
}
