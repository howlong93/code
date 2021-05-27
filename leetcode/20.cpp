class Solution {
   public:
    bool isValid(string s) {
        stack<char> temp;
        for (auto k : s) {
            if (k == '[' || k == '{' || k == '(')
                temp.push(k);
            else if (k == ']') {
                if (temp.empty() || temp.top() != '[') return false;
                temp.pop();
            } else if (k == ')') {
                if (temp.empty() || temp.top() != '(') return false;
                temp.pop();
            } else if (k == '}') {
                if (temp.empty() || temp.top() != '{') return false;
                temp.pop();
            }
        }

        if (temp.empty()) return true;
        return false;
    }
};
