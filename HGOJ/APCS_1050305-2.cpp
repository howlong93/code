#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

void flip(int, int, int);
void turn(int, int, int);
void copy(int, int, int);

int data[MAX][MAX] = {0};
int cpy[MAX][MAX] = {0};

int main() {
    int row = 0, col = 0, amount = 0, keep = 0;
    cin >> row >> col >> amount;

    keep = max(row, col);

    int i = 0, j = 0, action[amount] = {0};

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cin >> data[i][j];
        }
    }

    for (i = 0; i < amount; i++) {
        cin >> action[i];
    }

    for (int step = amount - 1; step >= 0; step--) {
        if (action[step] == 0) {
            turn(row, col, keep);
            swap(row, col);
        } else {
            flip(row, col, keep);
        }
    }

    cout << row << " " << col << "\n";
    for (i = 0; i < row; i++) {
        cout << data[i][0];
        for (j = 1; j < col; j++) {
            cout << " " << data[i][j];
        }
        cout << "\n";
    }

    return 0;
}

void turn(int row, int col, int keep) {
    int i = 0, j = 0;
    copy(row, col, keep);
    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            data[i][j] = cpy[j][col - i - 1];
        }
    }
}

void flip(int row, int col, int keep) {
    int i = 0, j = 0;
    copy(row, col, keep);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            data[i][j] = cpy[row - i - 1][j];
        }
    }
}

void copy(int row, int col, int keep) {
    int i = 0, j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cpy[i][j] = data[i][j];
        }
    }
}
