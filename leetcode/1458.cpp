class Solution {
   public:
    vector<int> A, B;
    vector<vector<int>> mem;
    int dp(int i, int j) {
        if (i == 0 && j == 0) return A[i] * B[j];
        if (i < 0 || j < 0) return -1e9;
        if (mem[i][j] != -1e9) return mem[i][j];
        return mem[i][j] = max({dp(i - 1, j - 1) + A[i] * B[j], dp(i - 1, j),
                                dp(i, j - 1), A[i] * B[j]});
    }
    int maxDotProduct(vector<int>& _A, vector<int>& _B) {
        A = _A;
        B = _B;

        mem = vector<vector<int>>(A.size(), vector<int>(B.size(), -1e9));
        return dp(A.size() - 1, B.size() - 1);
        /*vector<vector<int>> dp (A.size(), vector<int>(B.size()));

        dp[0][0] = A[0] * B[0];
        for (size_t i = 1; i < A.size(); i++) {
            dp[i][0] = max (dp[i-1][0], A[i] * B[0]);
        }

        for (size_t j = 1; j < B.size(); j++) {
            dp[0][j] = max (dp[0][j-1], A[0] * B[j]);
        }

        for (size_t i = 1; i < A.size(); i++) {
            for (size_t j = 1; j < B.size(); j++) {
                dp[i][j] = max ({dp[i-1][j-1] + A[i] * B[j], dp[i-1][j],
        dp[i][j-1], A[i] * B[j]});
            }
        }

        return dp[A.size()-1][B.size()-1];
        */
    }
};
