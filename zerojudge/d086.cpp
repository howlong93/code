#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;

    cin >> input;
    while (input != "0") {
        int sum = 0;
        bool right = true;
        for (unsigned int i = 0; i < input.size(); i++) {
            if (isalpha(input[i])) {
                input[i] = tolower(input[i]);
                sum += input[i] - 'a' + 1;
            } else {
                cout << "Fail\n";
                right = false;
                break;
            }
        }

        if (right) cout << sum << "\n";
        cin >> input;
    }

    return 0;
}
