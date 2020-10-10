#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    int n;
    string input;

    cin >> n;

    getchar();
    getchar();
    while (n--) {
        map<string, int> data;
        int total = 0;

        while (getline(cin, input) && input != "") {
            data[input]++;
            total++;
        }

        for (auto k : data) {
            cout << k.first << " ";
            printf("%.4f\n", (k.second * 100.0) / total);
        }
        cout << "\n";
    }

    return 0;
}
