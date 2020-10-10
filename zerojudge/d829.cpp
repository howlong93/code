#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;

    cin >> input;
    while (input != "#") {
        if (next_permutation(input.begin(), input.end()))
            cout << input << "\n";
        else
            cout << "No Successor\n";

        cin >> input;
    }

    return 0;
}
