class Solution {
   public:
    vector<int> dist;
    double hour;
    bool check(int sp) {
        double cnt = 0;
        for (size_t i = 0; i < dist.size() - 1; i++) {
            if (dist[i] % sp)
                cnt += dist[i] / sp + 1;
            else
                cnt += dist[i] / sp;
        }
        cnt += (1.0 * dist[dist.size() - 1]) / sp;
        return cnt <= hour;
    }
    int minSpeedOnTime(vector<int>& _dist, double _hour) {
        dist = _dist;
        hour = _hour;
        int upper = 1e7, lower = 1;
        if (!check(upper)) return -1;
        int mid;
        while (upper >= lower) {
            mid = (upper + lower) / 2;
            if (check(mid))
                upper = mid - 1;
            else
                lower = mid + 1;
        }

        return lower;
    }
};
