#include <iostream>

using namespace std;

long long int calc(long long int);

int cnt;

int main() {
    long long int origin, amount;

    cin >> amount;
    while (amount--) {
        cnt = 0;
        cin >> origin;
        long long int ans = calc(origin);

        cout << cnt - 1 << " " << ans << "\n";
    }

    return 0;
}

long long int calc(long long int x) {
    long long int rever = -1, origin;

    while (rever != x) {
        cnt++;
        rever = 0;

        for (origin = x; origin > 0; origin /= 10) {
            rever *= 10;
            rever += origin % 10;
        }
        //      cout << x << "\n" << rever << "\n---------\n";

        if (rever == x && cnt > 1)
            break;
        else
            x = rever + x;
    }

    return rever;
}
