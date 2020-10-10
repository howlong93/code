#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    while (input != "0") {
        int odd = 0, even = 0;
        unsigned int i = 0;
        for (i = 0; i < input.size(); i++) {
            if (i % 2 == 0)
                even += input[i] - '0';
            else
                odd += input[i] - '0';
        }
        if ((odd - even) % 11 == 0)
            cout << input << " is a multiple of 11.\n";
        else
            cout << input << " is not a multiple of 11.\n";

        cin >> input;
    }

    return 0;
}
