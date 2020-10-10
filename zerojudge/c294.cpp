#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long int length[3] = {0}, i = 0, keep = 0, longest = 0;

    for (i = 0; i < 3; i++) {
        cin >> length[i];
    }

    sort(length, length + 3);
    cout << length[0] << " " << length[1] << " " << length[2] << "\n";

    if (length[0] + length[1] <= length[2]) {
        cout << "No\n";
        return 0;
    }

    keep = length[0] * length[0] + length[1] * length[1];
    longest = length[2] * length[2];

    if (keep < longest)
        cout << "Obtuse";
    else if (keep == longest)
        cout << "Right";
    else if (keep > longest)
        cout << "Acute";

    return 0;
}
