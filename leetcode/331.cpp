class Solution {
public:
    bool isValidSerialization(string preorder) {
        string cur;
        stringstream ss;
        ss << preorder;
        
        int node = 1;
        while (getline(ss, cur, ',')) {
            node--;
            if (node < 0) return false;
            if (cur != "#") node += 2;
        }
        
        return node == 0;
    }
};
