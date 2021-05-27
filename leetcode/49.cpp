class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> data;

        if (strs.size() == 0) return ans;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> temp = vector<int>(26);
            for (auto k : strs[i]) {
                temp[k - 'a']++;
            }

            data[temp].push_back(strs[i]);
        }

        for (auto k : data) {
            vector<string> temp;
            for (auto l : k.second) temp.push_back(l);
            ans.push_back(temp);
        }

        return ans;
    }
};
