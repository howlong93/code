class Solution {
   public:
    int maxEnvelopes(vector<vector<int>> &E) {
        sort(E.begin(), E.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });

        for (auto k : E)
            for (auto l : k) cout << l << ' ';

        vector<int> dp(E.size(), 1);
        int ans = 0;

        if (E.size()) dp[0] = 1;
        for (size_t i = 1; i < E.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (E[j][0] < E[i][0] && E[j][1] < E[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        for (auto k : dp) ans = max(ans, k);

        return ans;
    }
};
