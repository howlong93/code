class Solution {
   public:
    vector<int> partitionLabels(string S) {
        int data[26][2];
        int right_bound = 0, left_bound = 0;
        vector<int> ans;

        for (int i = 0; i < 26; i++) {
            data[i][0] = INT_MAX;
            data[i][1] = 0;
        }
        for (int i = 0; i < S.size(); i++) {
            data[S[i] - 'a'][0] = min(i, data[S[i] - 'a'][0]);
            data[S[i] - 'a'][1] = max(i, data[S[i] - 'a'][1]);
        }

        while (left_bound < S.size()) {
            for (int i = 0; i < 26; i++) {
                if (data[i][0] == left_bound) {
                    right_bound = data[i][1];
                }
            }

            int keep = -1;
            while (right_bound != keep) {
                keep = right_bound;
                for (int i = 0; i < 26; i++) {
                    if (data[i][0] <= data[i][1] && data[i][0] >= left_bound &&
                        data[i][0] < right_bound && data[i][1] > right_bound) {
                        right_bound = data[i][1];
                    }
                }
            }
            ans.emplace_back(right_bound - left_bound + 1);
            left_bound = right_bound + 1;
        }

        return ans;
    }
};
