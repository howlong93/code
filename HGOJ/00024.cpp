#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1005

int main() {
    vector<int> data;
    int keep = 0, maximum = 0;
    bool answer[MAX] = {true};
    for (cin >> keep; keep != 0; cin >> keep) {
        maximum++;
        data.emplace_back(keep);
    }

    for (int i = 1; i <= maximum; i++) {
        answer[i] = true;
    }
    for (auto k : data) {
        answer[k] = false;
    }

    for (int i = 1; i <= maximum; i++) {
        if (answer[i]) cout << i << " ";
    }

    return 0;
}
