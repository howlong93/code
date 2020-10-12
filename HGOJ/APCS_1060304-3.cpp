#include <iostream>

using namespace std;

#define MAX 55

int data[MAX][MAX];
bool visited[MAX][MAX] = {false};

int main() {
    int length = 0, keep = 1, i = 0, j = 0, move, cur_x = 0, cur_y = 0,
        first = 0;
    cin >> length >> first;

    cur_x = cur_y = length / 2;
    move = first;

    for (i = 0; i < length; i++)
        for (j = 0; j < length; j++) cin >> data[i][j];

    cout << data[cur_x][cur_y];
    while (!(visited[0][0] && visited[0][length - 1] &&
             visited[length - 1][0] && visited[length - 1][length - 1])) {
        if (visited[0][0] && visited[0][length - 1] && visited[length - 1][0] &&
            visited[length - 1][length - 1])
            break;

        if (move == 0)
            for (i = 0; i < keep; i++) {
                if (visited[0][0] && visited[0][length - 1] &&
                    visited[length - 1][0] && visited[length - 1][length - 1])
                    break;
                cur_x--;
                visited[cur_y][cur_x] = true;
                cout << data[cur_y][cur_x];
            }
        else if (move == 1)
            for (i = 0; i < keep; i++) {
                if (visited[0][0] && visited[0][length - 1] &&
                    visited[length - 1][0] && visited[length - 1][length - 1])
                    break;
                cur_y--;
                visited[cur_y][cur_x] = true;
                cout << data[cur_y][cur_x];
            }
        else if (move == 2)
            for (i = 0; i < keep; i++) {
                if (visited[0][0] && visited[0][length - 1] &&
                    visited[length - 1][0] && visited[length - 1][length - 1])
                    break;
                cur_x++;
                visited[cur_y][cur_x] = true;
                cout << data[cur_y][cur_x];
            }
        else if (move == 3)
            for (i = 0; i < keep; i++) {
                if (visited[0][0] && visited[0][length - 1] &&
                    visited[length - 1][0] && visited[length - 1][length - 1])
                    break;
                cur_y++;
                visited[cur_y][cur_x] = true;
                cout << data[cur_y][cur_x];
            }

        move = (move + 1) % 4;

        if (first - move == 0 || first - move == 2 || first - move == -2) {
            keep++;
        }
    }

    return 0;
}
