class Solution {
   public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> dist;
        int ans = 0;
        for (size_t i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                cout << i << ' ';
                dist.push_back(i);
                int temp = i - dist[dist.size() - 1];
                cout << temp << '\n';
                if (dist.size() == 1)
                    ans = i;
                else
                    ans = max(ans, (int)(i - dist[dist.size() - 2]) / 2);
            }
        }

        ans = max(ans, (int)(seats.size() - dist[dist.size() - 1] - 1));
        return ans;
    }
};
