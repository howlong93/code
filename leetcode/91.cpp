class Solution {
   public:
    string s;
    vector<int> mem;
    int dp(int x) {
        if (x <= 0 && s[0] != '0') return 1;
        if (mem[x] != -5) return mem[x];

        if (s[x] == '0') {
            if (s[x - 1] == '1' || s[x - 1] == '2')
                return mem[x] = dp(x - 2);
            else
                return 0;
        } else {
            if (s[x - 1] == '1' || (s[x - 1] == '2' && s[x] <= '6'))
                return mem[x] = dp(x - 1) + dp(x - 2);
            else
                return mem[x] = dp(x - 1);
        }

        return 0;
    }
    int numDecodings(string _s) {
        s = _s;
        mem = vector<int>(s.size(), -5);

        mem[s.size() - 1] = dp(s.size() - 1);
        for (auto k : mem) cout << k << ' ';
        return mem[s.size() - 1];
        /*
        vector<int> dp (s.size());
        dp[0] = 1;
        if (s[0] == '0') return 0;
        if (s.size() > 1) {
            if (s[0] < '2'|| (s[0] == '2' && s[1] <= '6')) {
                if (s[1] == '0') dp[1] = 1;
                else dp[1] = 2;
            }
            else if (s[1] == '0') return 0;
            else dp[1] = 1;
        }
        for (size_t i = 2; i < s.size(); i++) {
            if (s[i-1] < '2' && s[i-1] != '0' && s[i] != '0'|| (s[i-1] == '2' &&
        s[i] <= '6')) { dp[i] = dp[i-1]+dp[i-2];
            }
            //else if (s[i] != '0') dp[i] = dp[i-1];
            else if (s[i] == '0' && (s[i-1] == '0' || s[i-1] > '2')) return 0;
            else if (s[i] == '0') dp[i] = dp[i-1]-1;
            else dp[i] = dp[i-1];

            if (dp[i] < 0) return 0;
        }

        for (auto k: dp) cout << k << ' ';
        return dp[s.size()-1];
        */
    }
};
