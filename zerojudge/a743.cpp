#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> data;

    int n;
    cin >> n;
    string input;

    getline(cin, input);

    while (n--) {
        getline(cin, input);
        stringstream ss;
        ss << input;
        ss >> input;
        data[input]++;
    }

    for (auto k : data) {
        cout << k.first << " " << k.second << "\n";
    }

    return 0;
}
