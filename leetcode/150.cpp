class Solution {
public:
    bool iscalc (string k) {
        return (k == "+" || k == "-" || k == "*" || k == "/");
    }
    int build_num (string k) {
        bool flag = false;
        if (k[0] == '-') {
            flag = true;
            k.erase (k.begin(), k.begin()+1);
        }
        int x = 0;
        for (auto l: k) x = x * 10 + l-'0';
        if (flag) x *= -1;
        return x;
    }
    int evalRPN(vector<string>& tokens) {
        stack <int> num;
        int ans = 0;
        for (auto &k: tokens) {
            if (iscalc(k)) {
                int x, y;
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                
                cout << x << ' ' << y << ' ';
                if (k == "+") num.push (x+y);
                else if (k == "-") num.push (x-y);
                else if (k == "*") num.push (x*y);
                else if (k == "/") num.push (x/y);
                cout << num.top() << '\n';
            }
            else num.push(build_num (k));
        }
        
        return num.top();
    }
};
