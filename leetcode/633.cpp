class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i*i <= c; i++) {
            long long x = (long long) sqrt (c-i*i);
            if (x*x + i*i == c) return true;
        }
        
        return false;
    }
};
