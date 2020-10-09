class Solution {
   public:
    string s1, s2;
    vector<vector<int>> mem;

    int dp(int i, int j) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (mem[i][j] != INT_MAX) return mem[i][j];

        if (s1[i - 1] == s2[j - 1]) return mem[i][j] = dp(i - 1, j - 1);
        return mem[i][j] =
                   1 + min({dp(i, j - 1), dp(i - 1, j), dp(i - 1, j - 1)});
    }
    int minDistance(string word1, string word2) {
        s1 = word1, s2 = word2;
        mem = vector<vector<int>>(s1.size() + 1,
                                  vector<int>(s2.size() + 1, INT_MAX));

        return dp(s1.size(), s2.size());
    }
};
