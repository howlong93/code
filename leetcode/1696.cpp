class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> q;

        q.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            if (q.front() < i - k) q.pop_front();
            nums[i] += nums[q.front()];
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }

        return nums.back();
    }
};
