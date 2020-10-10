#include <iostream>

using namespace std;

int main() {
    string input;

    while (cin >> input) {
        unsigned int i = 0, j = 0;
        for (i = 0; i < input.size(); i++) {
            if ((input[i] - '0') % 2 == 0) break;
        }

        string keep_low, keep_high;
        for (j = 0; j < i; j++) {
            keep_low += input[j];
            keep_high += input[j];
        }

        if (input[i] <= '9') {
            keep_high += char(input[i] + 1);
            for (j = i + 1; j < input.size(); j++) {
                keep_high += char('1');
            }
        }

        if (input[i] >= '1') {
            keep_low += char(input[i] - 1);
            for (j = i + 1; j < input.size(); j++) {
                keep_low += char('9');
            }
        } else if (i == 1) {
            keep_low[0] = '0';
            for (j = i; j < input.size(); j++) {
                keep_low += char('9');
            }
        }

        long long int lower = 0, higher = 0, multi = 1, origin = 0;
        for (j = input.size() - 1;; j--) {
            lower += multi * (keep_low[j] - '0');
            higher += multi * (keep_high[j] - '0');
            origin += multi * (input[j] - '0');
            multi *= 10;
            if (j == 0) break;
        }

        cout << min((origin - lower), (higher - origin)) << "\n";
    }

    return 0;
}
