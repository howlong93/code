class Solution {
   public:
    int findSubstringInWraproundString(string p) {
        if (p.size() == 0) return 0;
        vector<int> dp(p.size(), 0);
        vector<int> fnd(26, 0);
        int keep = 2;
        dp[0] = 1;
        fnd[p[0] - 'a'] = 1;
        for (size_t i = 1; i < p.size(); i++) {
            if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26) {
                if (fnd[p[i] - 'a'] < keep) {
                    dp[i] = dp[i - 1] + keep - fnd[p[i] - 'a'];
                    fnd[p[i] - 'a'] = keep;
                    keep++;
                } else {
                    dp[i] = dp[i - 1];
                    keep++;
                }
            } else {
                if (fnd[p[i] - 'a'] == 0) {
                    dp[i] = dp[i - 1] + 1;
                    fnd[p[i] - 'a'] = 1;
                } else {
                    dp[i] = dp[i - 1];
                }
                keep = 2;
            }
        }
        for (auto k : dp) cout << k << ' ';

        return dp[p.size() - 1];
    }
};
