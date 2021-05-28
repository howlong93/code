class Solution {
   public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (check(i)) ans++;
        }

        return ans;
    }
    bool check(int x) {
        int temp = 0, ori = x, cnt = 1;
        bool flag = false;
        while (ori) {
            int c = ori % 10;
            ori /= 10;
            if (c == 2)
                temp += 5;
            else if (c == 5)
                temp += 2 * cnt;
            else if (c == 1)
                temp += 1 * cnt;
            else if (c == 6)
                temp += 9 * cnt;
            else if (c == 9)
                temp += 6 * cnt;
            else if (c == 0)
                temp += 0;
            else if (c == 8)
                temp += 8 * cnt;
            else
                return false;
            cnt *= 10;
        }
        if (temp != x) return true;

        return false;
    }
};
