class Solution {
   public:
    string s;
    int minCut(string _s) {
        s = _s;
        vector<int> dp(s.size(), 20000);

        if (s.size()) dp[0] = 0;

        cout << s.size() << '\n';
        for (int i = 1; i < s.size(); i++) {
            if (cpali(i, 0)) {
                dp[i] = 0;
                continue;
            }
            for (int j = i; j >= 1; j--) {
                if (dp[i] > dp[j - 1] + 1 && cpali(i, j)) {
                    dp[i] = dp[j - 1] + 1;
                }
            }
        }

        return dp[s.size() - 1];
    }
    bool cpali(int i, int j) {
        string keep = s.substr(j, i - j + 1), save = s.substr(j, i - j + 1);
        reverse(save.begin(), save.end());
        if (save != keep) return false;

        return true;
    }
};
