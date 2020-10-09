class Solution {
public:
    int numSquares(int n) {       
        vector<vector<int>> dp;
        int mxnum;
        for (mxnum = 1; mxnum * mxnum <= n; mxnum++);
        dp = vector<vector<int>> (mxnum, vector<int> (n+1, 10000000));
        
        for (int i = 0; i < mxnum; i++) dp[i][0] = 0;
        
        for (int i = 1; i < mxnum; i++) {
            for (int j = 1; j <= n; j++) {
                if (j-i*i >= 0) {
                    dp[i][j] = min (dp[i][j-i*i]+1, dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[mxnum-1][n];
    }
};
