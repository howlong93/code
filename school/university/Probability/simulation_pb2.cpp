#include <bits/stdc++.h>

using namespace std;

double uniform_rv() {
    return 1.0 * rand() / RAND_MAX;
}

double exponen_rv() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> exp_rand(0.4);

    double ret = exp_rand(gen);
    return ret;
}

class Circle {
   public:
    double x, y;
    double r;

    Circle() {
        x = uniform_rv() * 2 - 1;
        y = uniform_rv() * 20;
        r = exponen_rv();
    }

    int cnt_intersect() {
        int up_line = (int(y + r)) / 5;
        int low_line = (int(y - r)) / 5;
        return up_line - low_line + (y - r < 0 ? 1 : 0);
    }
};

double calc_expectation(const map<int, double> &intersection, int div) {
    double ret = 0;
    for (auto k : intersection) ret += k.first * k.second / div;
    return ret;
}

void output_data(int i, map<int, double> &intersection, double x_sum,
                 double y_sum, double r_sum) {
    cout << "\n" << string (40, '=') << '\n';
    cout << "b_" << i << " = " << intersection[1] / i << "\n";
    cout << "c_" << i << " = " << calc_expectation(intersection, i) << "\n\n";
    cout << "x-expect = " << x_sum / i << '\n';
    cout << "y-expect = " << y_sum / i << '\n';
    cout << "r-expect = " << r_sum / i << "\n";
    cout << string (40, '=') << '\n';
}

int main() {
    srand(time(NULL));

    int n;
    double x_sum = 0, y_sum = 0, r_sum = 0;
    map<int, double> intersection;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        Circle temp;
        intersection[temp.cnt_intersect()]++;

        x_sum += temp.x;
        y_sum += temp.y;
        r_sum += temp.r;

        cerr << i << '\n';
        cout << "b_" << i << " = " << intersection[1] / i << "\n";
        cout << "c_" << i << " = " << calc_expectation(intersection, i) << "\n\n";
    }

    for (auto k : intersection) {
        cout << setw(3) << k.first << " >> " << setw(7) << k.second << " || "
             << k.second / n << '\n';
    }

    output_data (n, intersection, x_sum, y_sum, r_sum);

    return 0;
}
