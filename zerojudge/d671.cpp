#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int line = 0;
    string input;

    cin >> line;
    getline(cin, input);

    while (line--) {
        getline(cin, input);
        int keep = 0;
        keep = (int)sqrt(input.size());
        if (keep * keep != input.size()) {
            cout << "INVALID\n";
        } else {
            int l = 0, k = 0;
            for (l = 0; l < keep; l++) {
                for (k = 0; k < keep; k++) {
                    cout << input[k * keep + l];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
