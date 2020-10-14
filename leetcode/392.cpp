class Solution {
   public:
    string s, t;
    vector<vector<int>> dp;

    size_t LCS(int x, int y) {
        if (x < 0 || y < 0) return 0;
        if (dp[x][y] != -1) return dp[x][y];

        if (s[x] == t[y]) return dp[x][y] = LCS(x - 1, y - 1) + 1;

        return dp[x][y] = max(LCS(x - 1, y), LCS(x, y - 1));
    }

    bool isSubsequence(string _s, string _t) {
        s = _s, t = _t;
        dp = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));

        LCS(s.size() - 1, t.size() - 1);
        for (auto k : dp) {
            for (auto l : k) cout << l << ' ';
            cout << '\n';
        }
        if (LCS(s.size() - 1, t.size() - 1) == s.size()) return true;

        return false;
    }
};
