#include <iostream>
#include <sstream>

using namespace std;

bool isnum(char x) {
    return (x >= '0' && x <= '9') ? true : false;
}

int main() {
    long long int cnt = 0;
    string input;

    while (cin >> input)
        for (char k : input) {
            if (isnum(k) || isalpha(k)) {
                cnt += 1;
                break;
            }
        }

    cout << cnt << "\n";

    return 0;
}
