#include <iostream>

using namespace std;

int main() {
    string input, encode;

    while (cin >> input >> encode) {
        int answer = 0, i = 0;
        for (i = 0; i < 26; i++) {
            if ((input[0] + i - 'A') % 26 == encode[0] - 'A') {
                answer = i;
                break;
            }
        }
        cout << answer << "\n";
    }

    return 0;
}
