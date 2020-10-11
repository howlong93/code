class Solution {
   public:
    int maxProfit(vector<int>& num) {
        int l, r, ans;
        vector<int> dp_s(num.size(), 0), dp_p(num.size(), 0),
            dp_dif(num.size(), 0);

        l = num[0], r = num[num.size() - 1];
        for (size_t i = 1; i < num.size(); i++) {
            dp_p[i] = max(dp_p[i - 1], num[i] - l);
            l = min(l, num[i]);
        }

        for (int i = num.size() - 2; i >= 0; i--) {
            dp_s[i] = max(dp_s[i + 1], r - num[i]);
            r = max(r, num[i]);
        }

        ans = dp_s[0];
        for (int i = 1; i < num.size(); i++)
            ans = max(ans, dp_p[i - 1] + dp_s[i]);

        return ans;
    }
};
