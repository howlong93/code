class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort (d.begin(), d.end(), [] (string &a, string &b) {
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        
        for (size_t i = 0; i < d.size(); i++) {
            if (check (d[i], s)) return d[i];
        }
        
        return "";
    }
    bool check (string sub, string s) {
        int cnt = 0;
        for (size_t i = 0, j = 0; i < sub.size() && j < s.size(); i++, j++) {
            while (j < s.size() && sub[i] != s[j]) j++;
            if (j < s.size() && sub[i] == s[j]) cnt++;
        }
        if (cnt == sub.size()) return true;
        return false;
    }
};
