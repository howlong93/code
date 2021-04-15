struct Point {
    int x, y;

    bool operator==(const Point &b) {
        return (x == b.x) & (y == b.y);
    }
    bool operator<(const Point &b) {
        return x < b.x;
    }
    Point operator+(const Point &b) {
        return {x + b.x, y + b.y};
    }
    Point operator-(const Point &b) {
        return {x - b.x, y - b.y};
    }
    Point operator*(const int &b) {
        return {x * b, y * b};
    }
    int operator*(const Point &b) {
        return {x * b.x + y * b.y};
    }
    int operator%(const Point &b) {
        return {x * b.y - y * b.x};
    }
};

void convexhull(vector<Point> &total, vector<Point> &convex) {
    int n = total.size(), m = 0;
    sort(total.begin(), total.end(),
         [](Point &a, Point &b) { return a.x < b.x; });
    convex.clear();

    for (int i = 0; i < n; i++) {
        while (m >= 2 &&
               (total[i] - convex[m - 2]) % (convex[m - 1] - convex[m - 2]) < 0)
            convex.pop_back(), m--;
        convex.emplace_back(total[i]), m++;
    }

    for (int i = n - 2; i >= 0; i--) {
        while (m >= 2 &&
               (total[i] - convex[m - 2]) % (convex[m - 1] - convex[m - 2]) < 0)
            convex.pop_back(), m--;
        convex.emplace_back(total[i]), m++;
    }

    if (convex.size() >= 2) convex.pop_back(), m--;
}
