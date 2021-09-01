// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            long long mid = (1LL * l+ 1LL * r)/2;
            bool cur = isBadVersion(mid), prev = isBadVersion(mid-1);
            if (cur == true && prev == false) return mid;
            
            if (cur == true && prev == true) r = mid-1;
            else if (cur == false && prev == false) l = mid+1;
        }
        
        return r;
    }
};
