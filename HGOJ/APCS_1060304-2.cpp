#include <iostream>
#include <vector>

using namespace std;

#define MAX 50000

bool visited[MAX] = {false};
int data[MAX] = {0};

int main() {
    int amount = 0, i = 0, cnt = 0, j = 0;
    cin >> amount;

    for (i = 0; i < amount; i++) {
        cin >> data[i];
    }

    for (i = 0; i < amount; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        j = i;
        while (!visited[data[j]]) {
            j = data[j];
            visited[j] = true;
        }

        cnt++;
    }

    cout << cnt;

    return 0;
}
