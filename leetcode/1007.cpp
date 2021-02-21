class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> cnta(7, 0), cntb(7, 0), cnts(7, 0);
        for (size_t i = 0; i < A.size(); i++) {
            cnta[A[i]]++, cntb[B[i]]++;
            if (A[i] == B[i]) cnts[A[i]]++;
        }
        
        int ans = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            if (cnta[i]+cntb[i]-cnts[i] == A.size()) {
                ans = min(ans, min (cnta[i], cntb[i])-cnts[i]);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
