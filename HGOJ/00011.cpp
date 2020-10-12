#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string a[3], keep = "-1";
    vector<string> answer;
    int i = 0, j = 0;

    for (i = 0; i < 3; i++) {
        cin >> a[i];
    }

    sort(a, a + 3);

    i = 0;
    do {
        keep = "";
        for (j = 0; j < 3; j++) {
            keep += a[j];
        }
        answer.push_back(keep);
        i++;
    } while (next_permutation(a, a + 3));

    sort(answer.begin(), answer.end());
    cout << *(answer.end() - 1) << "\n";

    for (auto k : answer) {
        cout << k << "\n";
    }

    return 0;
}
