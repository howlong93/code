#include <iostream>

using namespace std;

#define MAX 10005

int data[105] = {0}, dp[105][MAX] = {0};

int main() {
    int amount = 0, i = 0, j = 0, value = 0;
    cin >> amount >> value;

    for (i = 1; i <= amount; i++) {
        cin >> data[i];
    }

    for (i = 1; i <= amount; i++) {
        for (j = 0; j <= value; j++) {
            if (j >= data[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - data[i]] + data[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[amount][value] << "\n";

    return 0;
}
