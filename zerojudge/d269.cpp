#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, amount;
    cin >> n;

    while (n--) {
        int i;
        cin >> amount;
        vector<double> length(amount + 2, 0);

        for (i = 1; i <= amount; i++) cin >> length[i];

        sort(length.begin() + 1, length.begin() + amount + 1);
        double ans = 0;
        for (i = amount; i >= 3; i--)
            if (length[i] < length[i - 1] + length[i - 2]) {
                double sum = (length[i] + length[i - 1] + length[i - 2]) / 2;
                ans = max(ans, sqrt(sum * (sum - length[i - 2]) *
                                    (sum - length[i - 1]) * (sum - length[i])));
            }
        printf("%.2f\n", ans);
    }

    return 0;
}
