class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<int> mem, alpha (26);
        if (A.size() != B.size()) return false;
        
        for (size_t i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) mem.emplace_back(i);
            alpha[A[i]-'a']++;
        }
        
        if (!mem.size()) {
            for (int i = 0; i < 26; i++) {
                if (alpha[i] >= 2) return true;
            }
            return false;
        }
        if (mem.size() != 2) return false;
        
        if (A[mem[0]] == B[mem[1]] && A[mem[1]] == B[mem[0]]) return true;
        return false;
    }
};
