#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, char> A;
    A['1'] = '`', A['2'] = '1', A['3'] = '2', A['4'] = '3';

    A['5'] = '4', A['6'] = '5', A['7'] = '6', A['8'] = '7';

    A['9'] = '8', A['0'] = '9', A['-'] = '0', A['='] = '-';

    A['W'] = 'Q', A['E'] = 'W', A['R'] = 'E', A['T'] = 'R';

    A['Y'] = 'T', A['U'] = 'Y', A['I'] = 'U', A['O'] = 'I';

    A['P'] = 'O', A['['] = 'P', A[']'] = '[', A[92] = ']';

    A['S'] = 'A', A['D'] = 'S', A['F'] = 'D', A['G'] = 'F';

    A['H'] = 'G', A['J'] = 'H', A['K'] = 'J', A['L'] = 'K';

    A[';'] = 'L', A[39] = ';', A['X'] = 'Z', A['C'] = 'X';

    A['V'] = 'C', A['B'] = 'V', A['N'] = 'B', A['M'] = 'N';

    A[','] = 'M', A['.'] = ',', A['/'] = '.', A[' '] = ' ';

    string input;
    while (getline(cin, input)) {
        for (auto k : input) {
            cout << A[k];
        }
        cout << "\n";
    }

    return 0;
}
