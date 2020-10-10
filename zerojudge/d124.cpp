#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    while (cin >> input) {
        unsigned int i = 0, cnt = 0;

        if (input[0] == '-') i++;

        for (; i < input.size(); i++) cnt += input[i];

        if (cnt % 3 == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
