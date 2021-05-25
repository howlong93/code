class Solution {
   public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> pos;
        pos.emplace_back(0);
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                for (int j = pos.size() - 1; j >= 0 && i - pos[j] <= maxJump;
                     j--) {
                    if (i - pos[j] >= minJump) {
                        pos.emplace_back(i);
                        break;
                    }
                }
            }
        }

        if (pos[pos.size() - 1] == s.size() - 1) return true;
        return false;
    }
};
