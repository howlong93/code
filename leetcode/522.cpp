class Solution {
public:
    bool lcs (string a, string b) {
        if (a.size() > b.size()) return false;
        int cnt = 0;
        for (auto k: b) {
            if (a[cnt] == k) cnt++;
            if (cnt == a.size()) return true;
        }
        
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                if (lcs(strs[i], strs[j])) break;
            }
            if (j == strs.size()) ans = max (ans, (int)strs[i].size());
        }
        return ans;
    }
};
