#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<int> data;
    int choice;

    scanf("%d", &choice);
    while (choice != 0) {
        if (choice > 0) {
            data.emplace(choice);
        } else if (choice == -2) {
            if (data.size() > 0) {
                auto it = data.end();
                it--;
                cout << *(it) << " ";
                data.erase(it);
            }
        } else if (choice == -1) {
            if (data.size() > 0) {
                cout << *data.begin() << " ";
                data.erase(data.begin());
            }
        }
        scanf("%d", &choice);
    }
    cout << "\n";

    return 0;
}
