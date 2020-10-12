#include <iostream>

using namespace std;

int main() {
    string input;
    int amount = 0, i = 0;
    cin >> amount;

    for (i = 0; i < amount; i++) {
        long long int real = 0, keep = 1, sum = 0;
        long long int length = 0;
        char change = '\0';

        cin >> input >> change;
        for (length = input.size() - 1; length >= 0; length--) {
            real += keep * ((isalpha(input[length]) ? (input[length] - 'A' + 10)
                                                    : (input[length] - '0')));
            sum += input[length] - (isalpha(input[length]) ? ('A' - 10) : '0');

            if (change == 'B')
                keep *= 2;
            else if (change == 'O')
                keep *= 8;
            else if (change == 'D')
                keep *= 10;
            else if (change == 'H')
                keep *= 16;
        }

        if (real % sum == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
