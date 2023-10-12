/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        if (n < 3) return false;

        int pk = fnd_pk (mountainArr);
        //cout << "peak at " << pk << ", value = " << mountainArr.get (pk) << '\n';

        int ret = -1;
        ret = bin_srch (mountainArr, 0, pk, target, 0);
        if (ret != -1) return ret;
        ret = bin_srch (mountainArr, pk+1, n-1, target, 1);

        return ret;
    }

    int fnd_pk (MountainArray &mount) {
        int l = 0, r = mount.length()-1;
        int mid = (l+r)/2;

        while (l <= r) {
            int prev, cur, post;
            prev = (mid >= 1) ? mount.get (mid-1) : -1;
            cur = mount.get(mid);
            post = (mid+1 < mount.length()) ? mount.get (mid+1) : -1;

            if (cur > prev && cur > post) return mid;
            
            if (cur > prev) l = mid+1;
            else if (cur < prev) r = mid-1;
            mid = (l+r)/2;
        }

        return mid;
    }

    int bin_srch (MountainArray &mount, int l, int r, int tar, bool dec_or_inc) {
        int mid = (l+r)/2;

        while (l <= r) {
            int cur = mount.get(mid);
            if (cur == tar) return mid;

            if (cur < tar && !dec_or_inc) l = mid+1;
            else if (cur < tar && dec_or_inc) r = mid-1;
            else if (cur > tar && !dec_or_inc) r = mid-1;
            else if (cur > tar && dec_or_inc) l = mid+1;

            mid = (l+r)/2;
        }

        return -1;
    }
};
