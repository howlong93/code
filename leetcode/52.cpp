class Solution {
   public:
    vector<vector<int>> pos;
    int ans = 0;
    void check(int cur, int lim) {
        for (int i = 0; i < lim; i++) {
            pos[cur][i] = 1;

            bool flag = false;
            for (int j = 1; j <= cur; j++)
                if (pos[cur - j][i]) flag = true;
            ;
            for (int j = 1; j <= cur && j <= i; j++)
                if (pos[cur - j][i - j]) flag = true;
            for (int j = 1; j <= cur && j < lim - i; j++)
                if (pos[cur - j][i + j]) flag = true;
            if (flag) {
                pos[cur][i] = 0;
            } else {
                if (cur == lim - 1) {
                    ans++;
                    for (auto k : pos) {
                        for (auto l : k) cout << l << ' ';
                        cout << '\n';
                    }
                    cout << '\n';
                } else
                    check(cur + 1, lim);
                pos[cur][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        pos = vector<vector<int>>(n, vector<int>(n, 0));
        check(0, n);

        return ans;
    }
};
