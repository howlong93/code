#include <iostream>

using namespace std;

int
main()
{
    int n = 0;
    cin >> n;
    while (n != 0)
    {
        while (n >= 10)
        {
            int sum = 0;
            sum += n%10;
            while (n /= 10) sum += n%10;

            n = sum;
        }
        cout << n << "\n";
        cin >> n;
    }

    return 0;
}
