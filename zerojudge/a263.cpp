#include <algorithm>
#include <iostream>

using namespace std;

struct saving_date {
    int year;
    int month;
    int day;
};

int each_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool spec(int);

int main() {
    saving_date data[2];

    while (cin >> data[0].year >> data[0].month >> data[0].day) {
        cin >> data[1].year >> data[1].month >> data[1].day;

        int cur_day[2] = {0}, i = 0;

        for (int j = 0; j <= 1; j++) {
            for (i = 0; i < data[j].month - 1; i++) {
                cur_day[j] += each_month[i];
                if (data[j].year > 0 && spec(data[j].year) && i == 1)
                    cur_day[j] += 1;
            }
            cur_day[j] += data[j].day;

            cur_day[j] += data[j].year * 365;
            cur_day[j] = cur_day[j] + (data[j].year - 1) / 4 -
                         (data[j].year - 1) / 100 + (data[j].year - 1) / 400;
        }

        cout << abs(cur_day[1] - cur_day[0]) << "\n";
    }
}

bool spec(int x) {
    if (x % 4 == 0 && x % 100 != 0)
        return true;
    else if (x % 400 == 0)
        return true;
    return false;
}
