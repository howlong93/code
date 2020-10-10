#include <iostream>

using namespace std;

bool isprime[1050] = {true};

void build_table(int);

int main() {
    string input;

    for (int i = 0; i <= 1040; i++) isprime[i] = true;
    build_table(2);

    while (cin >> input) {
        int sum = 0;
        for (auto k : input) {
            if (islower(k))
                sum += k - 'a' + 1;
            else
                sum += k - 'A' + 27;
        }

        cout << "It is " << (isprime[sum] ? "" : "not ") << "a prime word.\n";
    }

    return 0;
}

void build_table(int x) {
    if (x >= 35) return;
    if (isprime[x]) {
        for (int i = x + x; i <= 1050; i += x) isprime[i] = false;
    }
    build_table(x + 1);
}
