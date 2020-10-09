class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort (pairs.begin(), pairs.end(),
             [] (vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        
        vector<int> dp (pairs.size(), 1);
        int ans = 0;
        
        if (pairs.size()) dp[0] = 1;
        for (size_t i = 1; i < pairs.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) dp[i] = max (dp[i], dp[j]+1);
            }
        }
        
        for (size_t i = 0; i < pairs.size(); i++) ans = max (ans, dp[i]);
        
        return ans;
    }
};
