class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<int> jobs(n);
        for(int i=0;i<n;i++)jobs[i]=i;
        
        sort(jobs.begin(),jobs.end(),[&endTime](int a, int b) {
            return endTime[a]<endTime[b];
        });
        
        map<int,int>dp;
        
        dp[0]=0;
        
        for(auto &t: jobs) {
            int val = prev(dp.upper_bound(startTime[t]))->second + profit[t];
            if(val > dp.rbegin()->second) dp[endTime[t]] = val;
        }

        return dp.rbegin()->second;
    }
};
