/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> num;
    TreeNode *root;
    bool check(TreeNode *cur, TreeNode *comp) {
        if (cur == nullptr && comp == nullptr) return true;
        if (cur == nullptr || comp == nullptr) return false;
        if (cur->val != comp->val) return false;
        return check(cur->left, comp->left) & check(cur->right, comp->right);
    }
    void insert(TreeNode *&cur, int x) {
        if (cur == nullptr) {
            cur = new TreeNode(x);
            return;
        }

        if (cur->val > x)
            insert(cur->left, x);
        else
            insert(cur->right, x);
    }
    vector<TreeNode *> generateTrees(int n) {
        num = vector<int>(n);
        for (int i = 1; i <= n; i++) num[i - 1] = i;

        vector<TreeNode *> ret;
        do {
            bool flag = true;
            root = nullptr;
            for (int i = 0; i < n; i++) insert(root, num[i]);
            for (int i = 0; i < ret.size(); i++) {
                if (check(root, ret[i])) {
                    flag = false;
                    break;
                };
            }
            if (flag) ret.push_back(root);
        } while (next_permutation(num.begin(), num.end()));

        return ret;
    }
};
