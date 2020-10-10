#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int table[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21,
                     22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    int data[26] = {0};
    long long int input;
    cin >> input;

    int last = 0, calc = 0, i = 0;

    last = input % 10;
    input /= 10;

    for (i = 1; i <= 8; i++) {
        calc += (input % 10) * i;
        input /= 10;
    }

    for (i = 0; i < 26; i++) {
        data[i] = (table[i] / 10 + table[i] % 10 * 9) % 10;
        //      cout << calc << " " << data[i] << "\n";
        if (10 - (calc + data[i]) % 10 == last)
            cout << char(i + 65);
        else if ((calc + data[i]) % 10 == 0 && last == 0)
            cout << char(i + 65);
    }

    return 0;
}
