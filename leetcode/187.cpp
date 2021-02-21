class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 10) return ans;
        unordered_map <string, int> data;
        string keep;
        
        for (int i = 0; i < 10; i++) {
            keep += s[i];
        }
        data[keep]++;
        
        for (int i = 10; i < s.size(); i++) {
            keep.erase (keep.begin(), keep.begin()+1);
            keep += s[i];
            data[keep]++;
        }
        
        for (auto k: data) {
            if (k.second > 1){
                ans.emplace_back (k.first);
            }
        }
        
        return ans;
    }
};
