#include <iostream>

using namespace std;

int main() {
    int test_case_num;
    cin >> test_case_num;

    int ant_num, length, time;
    cin >> length >> ant_num >> time;

    int count = ant_num;
    for (int i = 0; i < ant_num; i++) {
        int pos;
        char dir;

        cin >> pos >> dir;
        if (dir == 'L' && pos < time) count--;
        else if (dir == 'R' && pos+time > length) count--;

        cout << count << '\n';
    }

    return 0;
}
