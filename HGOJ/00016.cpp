#include <iostream>

using namespace std;

int main() {
    int first = 0, n = 0, nth = 0;

    cin >> first >> nth >> n;

    cout << (nth - first) / (n - 1) << "\n";

    return 0;
}
