class Solution {
   public:
    vector<int> LIS;
    int lengthOfLIS(vector<int>& nums) {
        LIS = vector<int>(nums.size(), INT_MAX);

        for (size_t i = 0; i < nums.size(); i++) {
            size_t pos = binarySearch(nums[i]);
            LIS[pos] = nums[i];
        }

        size_t i;
        for (i = 0; i < nums.size(); i++) {
            if (LIS[i] == INT_MAX) break;
        }

        return i;
    }
    int binarySearch(int x) {
        int upper = LIS.size() - 1, lower = 0;
        int mid;

        while (upper != lower) {
            mid = (lower + upper) / 2;
            if (x <= LIS[mid]) {
                upper = mid;
            } else if (x > LIS[mid]) {
                lower = mid + 1;
            }
        }

        return upper;
    }
};
