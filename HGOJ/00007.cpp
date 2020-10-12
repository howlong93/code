#include <iostream>

using namespace std;

#define MAX 10005

int data[MAX] = {0}, dp[MAX] = {0};

int main() {
    int amount = 0, i = 0, j = 0;
    cin >> amount;

    for (i = 1; i <= amount; i++) {
        cin >> data[i];
    }

    dp[1] = data[1];
    for (i = 1; i <= amount; i++) {
        dp[i] = data[i];
        for (j = 1; j < i; j++) {
            if (data[j] < data[i]) dp[i] = max(dp[i], dp[j] + data[i]);
        }
    }

    j = 0;
    for (i = 1; i <= amount; i++) {
        j = max(dp[i], j);
    }

    cout << j;

    return 0;
}
