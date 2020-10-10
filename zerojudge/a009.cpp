#include <iostream>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    for (unsigned int i = 0; i < input.size(); i++) {
        input[i] = input[i] - 7;
    }

    cout << input;
    return 0;
}
