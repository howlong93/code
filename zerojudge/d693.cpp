#include <iostream>
#include <vector>

using namespace std;

int gcd (int x, int y);

int
main()
{
    long long int amount, i, keep_gcd, ans;
    cin >> amount;

    while (amount > 0)
    {
        ans = 1;
        vector<long long int> data(amount);
        for (i = 0; i < amount; i++)
            cin >> data[i];

        keep_gcd = gcd (data[0], data[1]);
        ans = data[0] * data[1] / keep_gcd;

        for (i = 2; i < amount; i++)
        {
            keep_gcd = gcd (ans, data[i]);
            ans = ans/keep_gcd * data[i];
        }

        cout << ans << "\n";
        cin >> amount;
    }

    return 0;
}

int
gcd (int x, int y)
{
    if (x % y == 0) return y;
    else return gcd (y, x%y);
}
