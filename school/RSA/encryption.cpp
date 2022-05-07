#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sstream>

using namespace std;

long long int gcd_reverse(long long int, long long int);
long long int fast_mod(long long int, long long int, long long int);
long long int choose_public_key(long long int);

int
main() {
        long long int prime_1 = 0, prime_2 = 0, public_key = 0, private_key = 0, saving = 0;

        cerr << "prime_1 prime_2: ";
        cin >> prime_1 >> prime_2;
        saving = (prime_1-1) * (prime_2-1);

        public_key = choose_public_key(saving);
        cerr << "\npublic_key: " << public_key << endl;

        private_key = gcd_reverse(public_key, saving);

        long long int turn_number = 0, private_message = 1, saving_pq = prime_1 * prime_2;

        cerr << "private_key: ";
        cout << private_key << endl;

        cerr << endl << "P*Q = ";
        cout << saving_pq << endl;
        cerr << endl;

        cerr << "message: ";
        string input;
        getline(cin, input);
        getline(cin, input);

        for (unsigned long long int pos = 0; pos < input.size(); pos++) {
                char c = input[pos];

                if (c == ' ') {
                        turn_number = 62;
                }
                else if (c >= '0' && c <= '9') {
                        turn_number = c-'0';
                }
                else if (c >= 'a' && c <= 'z') {
                        turn_number = c-'a'+10;
                }
                else if (c >= 'A' && c <= 'Z') {
                        turn_number = c-'A'+36;
                }
                else {
                        turn_number = 63;
                }

                //turn_number ^ public_key % pq;
                private_message = fast_mod (turn_number, public_key, saving_pq);

                cout << private_message << " ";
        }

        cerr << endl;

        return 0;
}

long long int
gcd_reverse(long long int key, long long int multi)
{
        vector<long long int> quotion, remainder;
        long long int a = multi, b = key, keep = 0;

        remainder.push_back(multi);
        remainder.push_back(key);

        //saving
        while (b != 1) {
                remainder.push_back(a%b);
                quotion.push_back(a/b);
                keep = a % b;
                a = b;
                b = keep;
        }

        long long int keep_left = 0, keep_right = 0;

        if (quotion.size() % 2 == 1) {
                keep_left = 1;
        }
        else {
                keep_right = 1;
        }

        //reversing
        for (long long int j = quotion.size()-1; j >= 0; j--){

                //at left
                if (j % 2 == 0) {
                        keep_right += -(keep_left * quotion[j]);
                }
                //at right
                else {
                        keep_left += -(quotion[j] * keep_right);
                }
        }

        if (keep_right < 0) {
                keep_right += multi;
        }

        return keep_right;
}

long long int
fast_mod(long long int base, long long int times, long long int divisor)
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

long long int
choose_public_key (long long int r)
{
int data[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        long long int answer = 1, count = 0;

        for (int i = 0; i < 25; i++) {
                if (r % data[i] != 0) {
                        answer *= data[i];
                        count++;
                        if (count >= 4) {
                                break;
                        }
                }
        }
        return answer;
}
