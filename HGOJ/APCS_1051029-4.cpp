#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> data[9];
    string a;
    int i = 0, amount = 0, j = 0, out = 0, goal = 0, player = 0, score = 0,
        round = 0;
    bool base[3] = {0};

    for (i = 0; i < 9; i++) {
        cin >> amount;
        for (j = 0; j < amount; j++) {
            cin >> a;
            data[i].push_back(a);
        }
    }
    cin >> goal;

    while (out < goal) {
        if (data[player][round][1] == 'O') {
            out++;
            if (out % 3 == 0)
                for (i = 0; i < 3; i++) base[i] = 0;
        }

        else if (data[player][round] == "HR") {
            int cnt = 0;
            for (i = 0; i < 3; i++) {
                if (base[i]) {
                    score++;
                    cnt++;
                }
                base[i] = 0;
            }
            score++;
            //			cout << cnt+1 << "point homerun\n";
        }

        else if (data[player][round][1] == 'B') {
            for (i = 0; i < data[player][round][0] - '0'; i++) {
                if (base[2] == 1) {
                    //					cout << "score\n";
                    base[2] = 0;
                    score++;
                }

                for (j = 1; j >= 0; j--) {
                    if (base[j] == 1) {
                        //						cout << j+1 << "
                        //to " << j+2 << endl;
                        base[j + 1] = base[j];
                        base[j] = 0;
                    }
                }
            }
            base[data[player][round][0] - '0' - 1] = 1;
        }
        player = (player + 1) % 9;
        if (player == 0) round++;
    }

    cout << score;

    return 0;
}
