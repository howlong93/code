#include <bits/stdc++.h>

using namespace std;

double uniform_rv() {
    return 1.0 * rand() / RAND_MAX;
}

class Circle {
   public:
    double x, y;
    double r;

    Circle() {
        x = uniform_rv() * 2 - 1;
        y = uniform_rv() * 20;
        r = uniform_rv() * 1.25;
    }

    int cnt_intersect() {
        int up_line = (int(y + r)) / 5;
        int low_line = (int(y - r)) / 5;
        return up_line - low_line + (y - r < 0 ? 1 : 0);
    }
};

void output_data(int n, double x, double y, double r, double a) {
    cout << '\n' << string (40, '=') << '\n';
    cout << "a" << n << " = " << a / n << "\n";
    cout << '\n';
    cout << "x-expect = " << x / n << '\n';
    cout << "y-expect = " << y / n << '\n';
    cout << "r-expect = " << r / n << "\n";
    cout << string (40, '=') << '\n';

    return;
}

int main() {
    srand(time(NULL));

    int n;
    cin >> n;
    double cnt = 0, x_sum = 0, y_sum = 0, r_sum = 0;

    for (int i = 1; i <= n; i++) {
        Circle temp;
        cnt += temp.cnt_intersect();

        x_sum += temp.x, y_sum += temp.y, r_sum += temp.r;
        cout << "a_" << i << " = " << cnt/i << '\n';
    }

    output_data (n, x_sum, y_sum, r_sum, cnt);

    return 0;
}
