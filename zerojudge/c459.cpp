#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int forward = 0, times = 1, calc = 0, sum = 0;

    cin >> forward >> input;
    for (int i = input.size() - 1; i >= 0; i--) {
        calc += (input[i] - '0') * times;
        times *= forward;
    }

    for (unsigned int i = 0; i < input.size(); i++) {
        int keep = 1;
        for (unsigned int l = 0; l < input.size(); l++) {
            keep *= (input[i] - '0');
        }
        sum += keep;
    }

    if (calc == sum)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
