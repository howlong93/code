#include <climits>
#include <iostream>

using namespace std;

#define MAX 105

int main() {
    int hour = 0, minute = 0, friends[MAX] = {0}, a = 0, b = 0, amount = 0,
        i = 0;
    const int total = 60 * 24;

    cin >> hour >> minute >> amount;

    for (i = 0; i < amount; i++) {
        cin >> a >> b;
        a = a - hour;
        b = b - minute;

        int differ = abs(a * 60 + b);
        friends[i] = min(differ, total - differ);
    }

    a = 0;
    for (i = 1; i < amount; i++) {
        if (friends[i] < friends[a]) a = i;
    }

    cout << a << " " << friends[a];

    return 0;
}
