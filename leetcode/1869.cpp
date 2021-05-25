class Solution {
public:
    bool checkZeroOnes(string s) {
        int cntx, cnty, maxx, maxy;
        cntx = cnty = maxx = maxy = 0;
        
        if (s[0] == '0') cntx++;
        else cnty++;
        
        for (size_t i = 1; i < s.size(); i++) {
            char k = s[i];
            if (k == '0') {
                if (cnty > 0) {
                    maxy = max (cnty, maxy); cnty = 0;
                }
                cntx++;
            }
            else {
                if (cntx > 0) {
                    maxx = max (cntx, maxx); cntx = 0;
                }
                cnty++;
            }
        }
        maxx = max (cntx, maxx);
        maxy = max (cnty, maxy);
        
        cout << maxx << ' ' << maxy << '\n';
        
        if (maxx < maxy) return true;
        else return false;
    }
};
