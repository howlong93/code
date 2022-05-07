#include <iostream>
#include <vector>

using namespace std;

int fast (long long int, long long int, long long int);

int
main()
{
        long long int i = 0, prime_multi = 0;
        long long int private_key = 0;
        cout << "private key: ";
        cin >> private_key;
        cout << endl;

        cout << "p * q = ";
        cin >> prime_multi;
        cout << endl;

        vector<long long int> saving;
        char c = '\0';
        while (cin >> i) {
                saving.push_back(i);
        }

		cerr << "origin message: ";
        for (auto k: saving) {

                int number = fast(k, private_key, prime_multi);
                if (number == 62) {
                        c = ' ';
                }
                else if (number >= 0 && number <= 9) {
                        c = number + '0';
                }
                else if (number >= 10 && number <= 35) {
                        c = number -10 + 'a';
                }
                else if (number >= 36 && number <= 61) {
                        c = number -36 + 'A';
                }

                cout << c;
        }

        cout << endl;

        return 0;
}

int fast(long long int base, long long int times, long long int divisor)
{
    long long int res, t;
    res = 1 % divisor;
    t = base % divisor;
    while (times)
    {
        if (times & 1)
        {
            res = res * t % divisor;
        }
        t = t * t % divisor;
        times >>= 1;
    }
    return res;
}
