class Solution {
   public:
    vector<bool> dp;
    vector<string> ss;
    string s;
    bool wordBreak(string _s, vector<string>& wordDict) {
        ss = wordDict;
        dp = vector<bool>(_s.size(), false);
        s = _s;

        for (size_t i = 0; i < s.size(); i++) {
            for (size_t j = 0; j <= i; j++) {
                if (check(i, j)) {
                    if (j > 0) {
                        if (dp[j - 1] == true) {
                            dp[i] = dp[j - 1];
                            break;
                        }
                    } else {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        for (auto k : dp) cout << k << ' ';

        return dp[s.size() - 1];
    }

    bool check(int i, int j) {
        string keep = s.substr(j, i - j + 1);
        cout << i << ' ' << j << ' ' << keep << '\n';
        for (auto k : ss) {
            if (k == keep) return true;
        }

        return false;
    }
};
