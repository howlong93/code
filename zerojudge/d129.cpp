#include <bits/stdc++.h>

using namespace std;

long long int MAX_CNT() {
    long long int ret = 0;
    for (int i = 2; i < 1502; i++) {
        ret += i * (i - 1) / 2;
    }

    return ret;
}

int main() {
    long long int large = MAX_CNT();
    long long int i, keep;
    set<long long int> data;
    queue<long long int> q;

    q.push(1);
    for (long long int k = 0; k < large; k++) {
        i = q.front();
        if (data.find(i) == data.end()) {
            data.emplace(i);
            if (i < LLONG_MAX / 2) q.push(i * 2);
            if (i < LLONG_MAX / 3) q.push(i * 3);
            if (i < LLONG_MAX / 5) q.push(i * 5);
        }
        if (q.size() > 0)
            q.pop();
        else
            break;
    }

    for (i = 0; i < 1500; i++) {
        keep = *data.begin();
        data.erase(data.begin());
    }
    cout << "The 1500'th ugly number is " << keep << ".\n";

    return 0;
}
