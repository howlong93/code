class Solution {
   public:
    int maxProduct(vector<string>& words) {
        vector<set<char>> data = vector<set<char>>(words.size());
        for (size_t i = 0; i < words.size(); i++) {
            for (auto l : words[i]) {
                data[i].insert(l);
            }
        }

        int ans = 0;
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = i + 1; j < data.size(); j++) {
                bool flag = true;
                for (auto k : data[i]) {
                    if (data[j].find(k) != data[j].end()) {
                        flag = false;
                        break;
                    }
                }

                int temp = words[i].size() * words[j].size();
                if (flag && temp > ans) ans = temp;
            }
        }

        return ans;
    }
};
