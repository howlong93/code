#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int a = 0, b = 0, c = 0;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'Y' || s[i] == 'y') a++;
            if (s[i] == 'T' || s[i] == 't') b++;
            if (s[i] == 'P' || s[i] == 'p') c++;
        }
    }
    cout << min(a, min(b, c));
}
