class Solution {
   public:
    string largestTimeFromDigits(vector<int>& a) {
        sort(a.begin(), a.end());
        int hour, minute;
        string answer;

        do {
            hour = a[0] * 10 + a[1];
            minute = a[2] * 10 + a[3];
            if (hour < 24 && minute < 60) {
                answer = "";
                stringstream ss;
                answer += char(hour / 10 + '0');
                answer += char(hour % 10 + '0');
                answer += ":";
                answer += char(minute / 10 + '0');
                answer += char(minute % 10 + '0');
            }
        } while (next_permutation(a.begin(), a.end()));

        return answer;
    }
};
