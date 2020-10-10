#include <bits/stdc++.h>

using namespace std;

struct saving_data {
    int num;
    int height;
    int weight;
};

int main() {
    long long int n, i, cnt = 0, j;
    cin >> n;

    vector<saving_data> data(n);
    for (i = 0; i < n; i++) {
        data[i].num = i + 1;
        cin >> data[i].height >> data[i].weight;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (data[j].height > data[j + 1].height ||
                (data[j].height == data[j + 1].height &&
                 data[j].weight > data[j + 1].weight)) {
                swap(data[j], data[j + 1]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        cnt += abs(data[i].num - (i + 1));
    }

    cout << cnt << "\n";
    return 0;
}
