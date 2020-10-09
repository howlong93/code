class Solution {
   public:
    bool wordPattern(string pattern, string str) {
        int cnt_str = 0, cnt_pattern = 0;
        stringstream ss;
        string keep = str;
        ss << keep;
        while (ss >> keep) cnt_str++;
        for (auto k : pattern) cnt_pattern++;
        if (cnt_pattern != cnt_str) return false;

        map<char, string> data;
        stringstream ll;
        ll << str;
        for (auto k : pattern) {
            ll >> str;
            cout << "::::::" << k << ' ' << str << '\n';
            if (data.count(k) == 0) {
                data[k] = str;
            } else {
                if (str == data[k]) continue;
                cout << "wrong place\n" << str << ' ' << data[k] << '\n';
                return false;
            }
        }

        for (auto k : data) {
            int cnt = 0;
            for (auto l : data)
                if (l.second == k.second) cnt++;

            if (cnt > 1) {
                cout << k.first << ' ' << cnt << '\n';
                return false;
            }
        }

        return true;
    }
};
