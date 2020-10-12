#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100005

int height[MAX] = {0};
vector<int> data[MAX];
bool keep_ancest[MAX] = {0};

int calc_height(int);

int main() {
    int amount = 0, i = 0, ancestor = 0;
    cin >> amount;

    for (i = 1; i <= amount; i++) {
        int ele = 0, dd = 0;
        cin >> ele;

        for (int l = 0; l < ele; l++) {
            cin >> dd;
            keep_ancest[dd] = 1;
            data[i].emplace_back(dd);
        }
    }

    for (i = 1; i <= amount; i++) {
        if (!keep_ancest[i]) {
            ancestor = i;
            break;
        }
    }

    calc_height(ancestor);

    int answer = 0;
    for (i = 1; i <= amount; i++) answer += height[i];

    cout << ancestor << "\n" << answer;

    return 0;
}

int calc_height(int pos) {
    if (data[pos].size() == 0)
        return 0;
    else {
        for (auto k : data[pos]) height[pos] = max(height[pos], calc_height(k));
    }
    height[pos]++;
    return height[pos];
}
