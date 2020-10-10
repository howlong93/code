#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;

    while (getline(cin, input)) {
        stringstream ss;
        double cnt_odd = 0, cnt_even = 0, data;
        int num;
        char f;

        ss << input;

        while (ss >> num >> f >> data) {
            if (num % 2 == 0)
                cnt_even += data;
            else
                cnt_odd += data;
        }

        cout << cnt_odd - cnt_even << "\n";
    }

    return 0;
}
