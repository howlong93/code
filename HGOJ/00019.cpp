#include <iostream>

using namespace std;

#define MAX 10005

bool success[MAX] = {false};

int main() {
    int n = 0, i = 0;

    cin >> n;

    success[2] = 1;
    success[3] = 0;
    for (i = 4; i <= n; i++) {
        for (int l = 1; l * l <= n; l++) {
            if (i % l == 0 && !success[i - l]) {
                success[i] = 1;
                break;
            }
        }
    }

    if (success[n])
        cout << "Win";
    else
        cout << "Lose";

    return 0;
}
