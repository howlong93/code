class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] = 0;
        if (num > 0) dp[1] = 1;
        
        for (int i = 2; i <= num; i++) {
            if (i % 2 == 0) dp[i] = dp[i/2];
            else dp[i] = dp[i-1]+1;
        }
        
        return dp;
    }
};
