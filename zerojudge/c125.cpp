#include <bits/stdc++.h>

using namespace std;

struct Edgetype {
    int fst, sec;
    double dist;
};

double calcdist(int a, int b) {
    return sqrt(a * a + b * b);
}

int main() {
    int pntamt, testcase = 1;
    cin >> pntamt;
    while (pntamt != 0) {
        int cur = 0;
        vector<pair<int, int>> pnt(pntamt);
        vector<double> keep(pntamt, INT_MAX), ans(pntamt, INT_MAX);
        vector<Edgetype> edge(pntamt * (pntamt - 1) / 2);

        for (int i = 0; i < pntamt; i++) cin >> pnt[i].first >> pnt[i].second;

        for (int i = 0; i < pntamt; i++) {
            for (int j = i + 1; j < pntamt; j++) {
                edge[cur].fst = i;
                edge[cur].sec = j;
                edge[cur++].dist = calcdist(pnt[i].first - pnt[j].first,
                                            pnt[i].second - pnt[j].second);
            }
        }

        ans[0] = keep[0] = 0;
        for (cur = 0; cur < pntamt; cur++) {
            for (auto k : edge) {
                if (ans[k.sec] == INT_MAX) ans[k.sec] = k.dist;
                if (ans[k.fst] == INT_MAX) ans[k.fst] = k.dist;

                keep[k.sec] = min(keep[k.sec], max(keep[k.fst], k.dist));

                keep[k.fst] = min(keep[k.fst], max(keep[k.sec], k.dist));
            }
            if (keep == ans)
                break;
            else
                ans = keep;
        }

        printf("Scenario #%d\nFrog Distance = %.3f\n\n", testcase++, ans[1]);
        cin >> pntamt;
    }

    return 0;
}
