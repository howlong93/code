class Solution {
   public:
    int minPartitions(string n) {
        int ans = 0;
        for (auto k : n) ans = max(k - '0', ans);

        return ans;
    }
};
