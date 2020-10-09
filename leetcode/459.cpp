class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        string substring, keep;
        for (size_t i = 0; i < s.size() / 2; i++) {
            substring += s[i];
            keep = substring;
            while (keep.size() < s.size()) keep += substring;

            if (keep == s) return true;
        }
        return false;
    }
};
