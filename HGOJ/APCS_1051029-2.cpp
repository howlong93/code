#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 30

int main() {
    int line = 0, amount = 0, data[MAX] = {0}, i = 0, j = 0, sum = 0;
    vector<int> answer;

    cin >> line >> amount;

    for (i = 1; i <= line; i++) {
        for (j = 1; j <= amount; j++) {
            cin >> sum;
            data[i] = max(data[i], sum);
        }
    }

    for (i = 1, sum = 0; i <= line; i++) {
        sum += data[i];
    }
    cout << sum << "\n";

    for (i = 1; i <= line; i++) {
        if (sum % data[i] == 0) {
            answer.emplace_back(data[i]);
        }
    }

    if (!answer.size())
        cout << -1;
    else {
        cout << answer[0];
        for (i = 1; i < answer.size(); i++) {
            cout << " " << answer[i];
        }
    }

    return 0;
}
