class Solution {
public:
    string itos(int x) {
        string ret;
        bool flag = false;
        if (x < 0) x *= -1, flag = true;
        while (x) {
            ret += char(x%10 + '0');
            x /= 10;
        }
        if (ret == "") return "0";
        reverse (ret.begin(), ret.end());
        if (flag) ret = "-" + ret;
        return ret;
    }
    string complexNumberMultiply(string num1, string num2) {
        int first[2], second[2];
        char c, e;
        
        stringstream ss;
        ss << num1;        
        ss >> first[0] >> c >> second[0] >> e;
        
        ss << num2;
        ss >> first[1] >> c >> second[1] >> e;
        
        int finf, fins;
        finf = first[0] * first[1] - second[0] * second[1];
        fins = first[0] * second[1] + first[1] * second[0];
        string ans = itos(finf) + "+" + itos(fins) + "i";
        return ans;
    }
};
