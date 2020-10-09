class Solution {
   public:
    int subarraysDivByK(vector<int>& A, int K) {
        int ans = 0;
        vector<int> pre_sum;
        map<int, int> cnt;

        pre_sum.emplace_back(0);
        for (size_t i = 0; i < A.size(); i++)
            pre_sum.emplace_back((pre_sum[i] + A[i]) % K);

        for (size_t i = 0; i < pre_sum.size(); i++) {
            if (pre_sum[i] < 0) pre_sum[i] += K;
            ans += cnt[pre_sum[i]]++;
        }

        return ans;
    }
};
