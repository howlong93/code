class Solution {
   public:
    vector<vector<int>> mem;
    string s1, s2;
    int longestCommonSubsequence(string text1, string text2) {
        mem = vector<vector<int>>(text1.size(),
                                  vector<int>(text2.size(), INT_MIN));
        s1 = text1, s2 = text2;

        return dp(s1.size() - 1, s2.size() - 1);
    }
    int dp(int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (mem[i][j] != INT_MIN) return mem[i][j];

        if (s1[i] == s2[j]) return mem[i][j] = dp(i - 1, j - 1) + 1;
        return mem[i][j] = max(dp(i - 1, j), dp(i, j - 1));
    }
};
