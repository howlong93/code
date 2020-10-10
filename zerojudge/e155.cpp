#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;
    while (n != 0) {
        int i = 0, cur = 0;
        deque<int> card;
        queue<int> thrown;

        for (i = 1; i <= n; i++) {
            card.emplace_back(i);
        }

        while (card.size() > 1) {
            thrown.push(card.front());
            card.pop_front();
            cur = card.front();
            card.pop_front();
            card.emplace_back(cur);
        }

        cout << "Discarded cards: ";

        if (thrown.size() >= 1) {
            cout << thrown.front();
            thrown.pop();
        }

        while (!thrown.empty()) {
            cout << ", " << thrown.front();
            thrown.pop();
        }
        cout << "\nRemaining card: " << card.front() << "\n";

        cin >> n;
    }

    return 0;
}
