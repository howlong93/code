class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, temp = 0;

        temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (temp > 0) {
                    ans = max(ans, temp);
                    temp = 0;
                }
            } else
                temp++;
        }
        return max(ans, temp);
    }
};
