#include <iostream>
#include <sstream>

using namespace std;

int main() {
    unsigned int amount = 0, i = 0;
    string lll;
    cin >> amount;

    cin.clear();
    getline(cin, lll);
    for (i = 0; i < amount; i++) {
        unsigned long long int cnt = 0, keep = 0;
        char plus;
        string input;
        stringstream ss;
        cin.clear();

        getline(cin, input);

        ss << input;
        ss >> cnt;
        while (ss >> plus >> keep) cnt += keep;

        cout << cnt << "\n";
    }

    return 0;
}
