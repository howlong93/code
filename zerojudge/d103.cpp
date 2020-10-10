#include <iostream>
#include <string>

using namespace std;

int main() {
    int cnt = 1, sum = 0, i = 0;
    string input;
    cin >> input;

    for (i = 0; i < 11; i++) {
        if (i == 1 || i == 5) continue;

        sum += (input[i] - '0') * cnt++;
    }

    if (sum % 11 == 10)
        if (input[12] == 'X')
            cout << "Right\n";
        else {
            for (i = 0; i <= 11; i++) cout << input[i];

            cout << "X\n";
        }
    else if (input[12] - '0' == sum % 11)
        cout << "Right\n";
    else {
        for (i = 0; i <= 11; i++) cout << input[i];

        cout << sum % 11 << "\n";
    }

    return 0;
}
