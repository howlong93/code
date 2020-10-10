#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a = 0, b = 0, c = 0, bottom = 1, top = 1;

    while (cin >> a >> b) {
        bottom = top = 1;
        c = max(b, a - b);
        b = min(b, a - b);
        vector<int> data(b);

        for (int i = 0; i < b; i++) data[i] = i + 1;

        for (int i = a; i > c; i--) {
            int k = i;
            for (int j = b - 1; j >= 1; j--) {
                if (data[j] > 1 && k % data[j] == 0) {
                    k /= data[j];
                    data[j] = 1;
                    if (k == 1) break;
                }
            }
            top *= k;
        }

        for (int i = 0; i < b; i++) bottom *= data[i];

        cout << top / bottom << "\n";
    }

    return 0;
}
