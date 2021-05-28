class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int l = 0, r = 0;
        vector<int> pos = vector<int>(nums.size(), nums.size() - 1),
                    pf = vector<int>(nums.size() + 1);
        map<int, int> temp;

        pf[0] = 0;
        for (size_t i = 1; i <= nums.size(); i++)
            pf[i] = pf[i - 1] + nums[i - 1];

        while (r < nums.size()) {
            while (temp[nums[r]] != 0) {
                temp[nums[l]]--;
                pos[l++] = r - 1;
            }
            temp[nums[r++]]++;
        }
        for (auto k : pos) cout << k << ' ';
        cout << '\n';
        int ans = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            ans = max(ans, pf[pos[i] + 1] - pf[i]);
        }

        return ans;
    }
};
