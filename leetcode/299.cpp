class Solution {
   public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        map<int, int> keep;

        for (auto k : secret) keep[k]++;

        for (auto k : guess) {
            if (keep[k] > 0) {
                b++;
                keep[k]--;
            }
        }

        for (size_t i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                a++;
                b--;
            }
        }

        stringstream ss, ll;
        string a_ans, b_ans;

        cout << a << ' ' << b << '\n';
        ss << a;
        ss >> a_ans;
        a_ans += 'A';
        ll << b;
        ll >> b_ans;
        b_ans += 'B';

        return a_ans + b_ans;
    }
};
