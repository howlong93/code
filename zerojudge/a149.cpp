#include <iostream>

using namespace std;

int main() {
    int n = 0;
    string input;
    cin >> n;

    while (n--) {
        int answer = 1;
        cin >> input;
        for (auto k : input) answer *= k - '0';

        cout << answer << "\n";
    }

    return 0;
}
